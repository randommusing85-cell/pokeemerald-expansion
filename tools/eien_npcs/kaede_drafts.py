#!/usr/bin/env python3
"""Overworld sprite drafts for Kaede and her grandparent (design/characters.md): recolors of
FRLG-style NPC megapack sheets (tools/fetch_assets.py frlg_npc_megapack). Writes
design/art/eien_kaede/drafts/*.png (RPG Maker sheets, like the pack's) and a contact sheet,
design/art/eien_kaede_ow_contact_sheet.png. Picked drafts are converted by convert.py.
  tools/eien_npcs/kaede_drafts.py
"""
import colorsys
import os
from PIL import Image, ImageDraw, ImageFont
REPO=os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
P=REPO+'/build/community_assets/frlg_npc_megapack/FRLG Accurate NPC Megapack (Relic Castle Edition)/'
OUT=REPO+'/design/art/eien_kaede/drafts/'
def tone(rgb, hue, sat, dl=0.0):
    h,l,s=colorsys.rgb_to_hls(*(c/255 for c in rgb))
    r,g,b=colorsys.hls_to_rgb(hue/360,max(0,min(1,l+dl)),sat)
    return tuple(round(c*255) for c in (r,g,b))
def recolor(path, rule):
    im=Image.open(P+path).convert('RGBA'); px=im.load(); fh=im.height//4
    for y in range(im.height):
        for x in range(im.width):
            p=px[x,y]
            if p[3]:
                n=rule(p[:3], y%fh, x%(im.width//4), y//fh)
                if n: px[x,y]=n+(255,)
    return im
MAROON=(128,64,96); MAROON_L=(168,96,128)
COAT={(248,248,248),(184,192,208),(128,128,136),(64,64,80)}
BAND={(72,72,128),(112,112,176)}
def kaede(coat_hue,coat_sat,coat_dl):
    def rule(c,y,x=0,d=0):
        # A07 wears glasses; paint them out: lenses become dark eyes, the rest skin
        if d<3 and 22<=y<=27 and 6<=x<=25:
            if c==(248,248,248):
                eye={0:(10,11,16,17),1:(8,9),2:(22,23)}[d]
                return (16,16,16) if x in eye else (248,208,176)
            if c==(184,192,208): return (240,184,144)
            if c==(16,16,16) and d==0 and y<=23: return (216,144,112)
        if c in (MAROON,MAROON_L):
            if y<32: return tone(c,20,0.25,-0.22)          # dark brown-black hair
            return tone(c,355,0.75,0.05)                   # red hakama
        if c in BAND:
            if y<30: return tone(c,0,0.0,0.5)              # white hair ribbon
            return tone(c,25,0.35,-0.15)                   # brown boots
        if c in COAT: return tone(c,coat_hue,coat_sat,coat_dl)
        return None
    return rule
drafts={
 'kaede_a_navy_coat': recolor('Anime NPCs/Characters/Anime NPC 07.png', kaede(225,0.35,-0.35)),
 'kaede_b_cream_coat': recolor('Anime NPCs/Characters/Anime NPC 07.png', kaede(40,0.30,-0.03)),
 'kaede_c_grey_coat': recolor('Anime NPCs/Characters/Anime NPC 07.png', kaede(0,0.08,-0.05)),
}
ORANGE={(216,104,72),(144,88,72)}
def elder(c,y,x=0,d=0):
    if c in ORANGE and y>=24: return tone(c,275,0.35,-0.05)   # purple hakama / robe
    if c in ORANGE: return tone(c,0,0.0,0.25)                # white upper robe
    return None
drafts['grandparent_a_medium']=Image.open(P+'HGSS NPCs/Characters/trainer_MEDIUM.png').convert('RGBA')
drafts['grandparent_b_medium_shrine']=recolor('HGSS NPCs/Characters/trainer_MEDIUM.png',elder)
drafts['grandparent_c_kurt']=Image.open(P+'HGSS NPCs/Characters/NPC_Kurt.png').convert('RGBA')
drafts['ref_anime_npc_07']=Image.open(P+'Anime NPCs/Characters/Anime NPC 07.png').convert('RGBA')
for n,im in drafts.items():
    if not n.startswith('ref'): im.save(OUT+n+'.png')
# contact sheet: each draft, 4 directions (first frame), x3
font=ImageFont.truetype('/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf',11)
order=['ref_anime_npc_07','kaede_a_navy_coat','kaede_b_cream_coat','kaede_c_grey_coat','grandparent_a_medium','grandparent_b_medium_shrine','grandparent_c_kurt']
S=3; fw,fh=32,48; cw=4*fw*S+16
sh=Image.new('RGB',(cw*4,2*(fh*S+22)+24),(152,208,160)); d=ImageDraw.Draw(sh)
d.text((6,4),'Kaede and her grandparent: overworld drafts (PROPOSALS). Facing down, left, right, up; x3. Recolors of FRLG-style megapack sheets.',fill=(0,0,0),font=font)
for i,n in enumerate(order):
    im=drafts[n]; x=(i%4)*cw+6; y=24+(i//4)*(fh*S+22)
    if i>=4: x=((i-4)%4)*cw+6
    for r in range(4):
        f=im.crop((0,r*fh,fw,(r+1)*fh)).resize((fw*S,fh*S),Image.NEAREST); sh.paste(f,(x+r*fw*S,y),f)
    d.text((x,y+fh*S+2),n,fill=(0,0,0),font=font)
sh.save(REPO+'/design/art/eien_kaede_ow_contact_sheet.png'); print(sh.size)

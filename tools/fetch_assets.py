#!/usr/bin/env python3
"""Download the community asset packs listed in design/asset-candidates.md.

Packs are unpacked into build/community_assets/<name>/ (build/ is git-ignored), so nothing
third-party is committed until it's chosen, converted and credited in
design/asset-credits.md.

  tools/fetch_assets.py            # all packs
  tools/fetch_assets.py cinna_snow johto
"""

import http.cookiejar
import io
import json
import os
import re
import sys
import urllib.parse
import urllib.request
import zipfile

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(REPO, "build", "community_assets")

# name: (kind, where)
PACKS = {
    "cinna_snow": ("eeveeexpo", 1631),  # CinnaYva, Gen 3 Snow Tileset (RMXP 2x)
    "johto": ("eeveeexpo", 1858),       # Alistair, Gen III Johto Tile Set (1x PNG)
    "ekat_tiles": ("eeveeexpo", 621),   # Ekat + others, 81 Gen 3 tilesets (1x)
    "mikitari_fakemon": ("eeveeexpo", 1517),  # Mikitari, Free Fakemon Pack (7z, 2x)
    "gen1_type_changed": ("itch", "https://digi5932.itch.io/gen-1-type-changed-pokemon"),
    "frlg_npc_megapack": ("eeveeexpo", 823),  # SoulfulLex (compiler), FRLG-style NPCs; credit the spriters
}

opener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(http.cookiejar.CookieJar()))
opener.addheaders = [("User-Agent", "Mozilla/5.0")]


def get(url, data=None):
    return opener.open(urllib.request.Request(url, data=data), timeout=300).read()


def resolve(url):
    """Follow a hosting page (Google Drive, MediaFire) to the file itself."""
    drive = re.search(r"drive\.google\.com/file/d/([^/]+)", url)
    if drive:
        return f"https://drive.usercontent.google.com/download?id={drive.group(1)}&export=download&confirm=t"
    if "mediafire.com" in url:
        page = get(url).decode("utf-8", "replace")
        return re.search(r'href="(https://download[^"]+)"', page).group(1)
    return url


def fetch_eeveeexpo(resource_id):
    req = urllib.request.Request(f"https://eeveeexpo.com/resources/{resource_id}/download")
    no_redirect = urllib.request.build_opener(type("NoRedirect", (urllib.request.HTTPRedirectHandler,),
                                                   {"redirect_request": lambda *a: None}))
    try:
        no_redirect.open(req, timeout=60)
        raise RuntimeError("expected a redirect to the file host")
    except urllib.error.HTTPError as e:
        return get(resolve(e.headers["Location"]))


def fetch_itch(page_url):
    page = get(page_url).decode("utf-8", "replace")
    token = re.search(r'name="csrf_token" value="([^"]+)"', page).group(1)
    upload = re.search(r'data-upload_id="(\d+)"', page).group(1)
    info = json.loads(get(f"{page_url}/file/{upload}", urllib.parse.urlencode({"csrf_token": token}).encode()))
    return get(info["url"])


def unpack(data, dest):
    os.makedirs(dest, exist_ok=True)
    if data[:2] == b"PK":
        zipfile.ZipFile(io.BytesIO(data)).extractall(dest)
    elif data[:6] == b"7z\xbc\xaf\x27\x1c":
        import py7zr  # pip install py7zr
        py7zr.SevenZipFile(io.BytesIO(data)).extractall(dest)
    elif data[:8] == b"\x89PNG\r\n\x1a\n":
        open(os.path.join(dest, "tileset.png"), "wb").write(data)
    else:
        raise RuntimeError("unknown archive format")


def main():
    names = sys.argv[1:] or list(PACKS)
    for name in names:
        kind, where = PACKS[name]
        print(f"{name}: downloading", flush=True)
        data = fetch_eeveeexpo(where) if kind == "eeveeexpo" else fetch_itch(where)
        unpack(data, os.path.join(OUT, name))
        print(f"{name}: {len(data) // 1024} KB -> {os.path.relpath(os.path.join(OUT, name), REPO)}")


if __name__ == "__main__":
    main()

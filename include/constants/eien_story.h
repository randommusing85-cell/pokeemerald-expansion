#ifndef GUARD_CONSTANTS_EIEN_STORY_H
#define GUARD_CONSTANTS_EIEN_STORY_H

// Main story progress, stored in VAR_EIEN_STORY (design/story-outline.md). Each value is a
// beat the hero has reached; the journal writes an entry for every beat up to the current
// one. Append new beats at the end of an act and never reorder: saves store the number.
// Only #defines here: scripts include this file too.

#define STORY_PROLOGUE          0   // our world; no journal yet
#define STORY_ARRIVED           1   // woke in Hamakaze, Celebi found him
#define STORY_TAKEN_IN          2   // the Kashiwagis took him in; he started the journal
#define STORY_GOT_STARTER       3   // picked a starter, first battle with Akira
#define STORY_ROUTE_1           4   // on Route 1
#define STORY_SHIMOTSUKI        5   // reached Shimotsuki; Akira showed him the gym
#define STORY_BADGE_1           6   // beat Fuyumi
#define STORY_MET_NAMI          7   // Nami helped him past Shimotsuki (end of milestone 1)
#define STORY_COUNT             8

#endif // GUARD_CONSTANTS_EIEN_STORY_H

#include <stdio.h>

/*
A RomSet is simply a set of ROMs located in a PCB. But since we're working
with the Pac-Man and Ms. Pac-Man ROM sets, this is how we're going to lay
out the struct. This is the base struct.
*/
typedef struct {
	FILE** PROGRAM_ROMS;
	FILE** SPRITE_ROMS;
	FILE** TILE_ROMS;
	FILE** COLOR_ROMS;
	FILE** AUDIO_ROMS;
} RomSet;

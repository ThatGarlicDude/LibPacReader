#include <stdio.h>

/*
A RomSet is simply a set of ROMs located in a PCB. But since we're working
with the Pac-Man and Ms. Pac-Man ROM sets, this is how we're going to lay
out the struct. This is the base struct.
*/
typedef struct {
	char** PROGRAM_ROMS;
	char** SPRITE_ROMS;
	char** TILE_ROMS;
	char** COLOR_ROMS;
	char** AUDIO_ROMS;
} RomSet;

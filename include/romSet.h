#ifndef ROM_SET_H
#define ROM_SET_H

	typedef struct {
		FILE** PROGRAM_ROMS;
		FILE** SPRITE_ROMS;
		FILE** TILE_ROMS;
		FILE** COLOR_ROMS;
		FILE** AUDIO_ROMS;
	} RomSet;

#endif

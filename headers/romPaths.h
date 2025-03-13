#ifndef ROM_PATHS_H
#define ROM_PATHS_H

	#include <stdio.h>

	typedef struct {
		char** filePaths;
		size_t size;
	} RomPaths;

	RomPaths newRomPaths();

	void addRomPath(RomPaths* romPathPointer, char* filePaths);

	void freeRomPath(RomPaths* romPathPointer);

	void printRomPaths(RomPaths* romPathPointer);

	size_t getRomPathSize(RomPaths* romPathPointer);

#endif

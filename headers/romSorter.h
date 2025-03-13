#ifndef ROM_SORTER_H
#define ROM_SORTER_H

	#include <dirent.h>
	#include <stdio.h>
	#include "romPaths.h"
	#include "romSet.h"

	const char* getFileExtension(const char fileName[]);

	RomPaths getFilePaths(const char fileName[]);

	void sortRomSet(RomPaths* romPathPointer, RomSet* romSetPointer);
#endif

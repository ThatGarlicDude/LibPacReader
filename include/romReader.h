#ifndef ROM_READER_H
#define ROM_READER_H

	#include <dirent.h>
	#include "romSet.h"
	#include "romVersion.h"

	RomSet readRomSet(DIR* romSetDir);

	RomSet readRomSetFromPath(char* romSetFilePath[]);

#endif

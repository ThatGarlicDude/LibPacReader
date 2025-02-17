#ifndef ROM_SORTER_H
#define ROM_SORTER_H

	#include <dirent.h>
	#include "romSet.h"

	void sortRomSet(DIR* directory, RomSet* romSet);

	const char* getFileExtension(char* fileNamePointer[]);
#endif

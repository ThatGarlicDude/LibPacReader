#include <stdio.h>
#include <dirent.h>
#include "romSet.h"
#include "romVersion.h"

// Reads and lays out the structure of the ROM set.
RomSet readRomSet(DIR* romSetDir) {
	RomSet romSet;
	return romSet;
}

// Ditto, but uses a filepath instead, just to make things easier.
RomSet readRomSetFromPath(char* romSetFilePath[]) {
	RomSet romSet;
	struct dirent* directoryEntry;
	DIR* directory = opendir(*romSetFilePath);
	if (directory == NULL) {
		printf("%s is not a directory.\n", *romSetFilePath);
		return romSet; // Just return an empty ROM set for now.
	} else {
		printf("%s is a directory.\n", *romSetFilePath);
	}
	romSet = readRomSet(directory);
	return romSet;
}

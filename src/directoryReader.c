#include <stdio.h>
#include <dirent.h>
#include "romSet.h"
#include "romSetHandler.h"
#include "romSorter.h"

// Reads a directory, and returns a ROM set.
RomSet readDirectory(char* directoryPath) {
	DIR* directory = opendir(directoryPath);
	struct dirent* entry;
	RomSet romSet = newROMSet();
	// Append the ROM files into the array.
	while ((entry = readdir(directory)) != NULL) {
		// Avoid referring to itself and parent directory.
		if (entry->d_name[0] == '.') {
			continue;
		}
		appendROM(&romSet, entry->d_name);
	}
	// Sort the ROM files.
	sortROMs(&romSet);
	closedir(directory);
	return romSet;
}

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "directoryGetter.h"
#include "romSet.h"
#include "romSetHandler.h"
#include "romSorter.h"

// Reads a directory, and returns a ROM set.
RomSet readDirectory(const char* directoryPath) {
	const char* cwd = getCurrentDirectory(directoryPath);
	DIR* directory = opendir(cwd);
	struct dirent* entry;
	RomSet romSet = newROMSet();
	printf("Reading directory...\n");
	// Fail if the directory isn't found.
	if (directory == NULL) {
		printf("%s is not a directory.\n", cwd);
		return romSet;
	}
	// Append the ROM files into the array.
	printf("Now appending the ROM files into the array.\n");
	while ((entry = readdir(directory)) != NULL) {
		const char* romName;
		// Avoid referring to itself and its parent directory.
		if (entry->d_name[0] == '.') {
			continue;
		}
		// Duplicate the string to a safe location, so it doesn't get overwritten by other functions.
		romName = strdup(entry->d_name);
		appendROM(&romSet, romName); // Please let this work instead of having these filenames get corrupted for virtually no reason.
	}
	// Sort the ROM files.
	sortROMs(&romSet);
	closedir(directory);
	return romSet;
}

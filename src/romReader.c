#include <stdio.h>
#include <dirent.h>
#include "romPaths.h"
#include "romSet.h"
#include "romSorter.h"
#include "romVersion.h"

// Simply opens up the directory to see if it's valid.
char isRomSetDirectoryValid(const char romSetFilePath[]) {
	DIR* directory = opendir(romSetFilePath);
	char result;
	// Is it valid?
	if (directory != NULL) {
		result++; // Increment it to false.
	}
	closedir(directory);
	return result;
}

// Reads and lays out the structure of the ROM set through a file path.
RomSet readRomSet(const char romSetFilePath[]) {
	RomSet romSet;
	RomPaths filePaths;
	// Check if the directory is valid or not.
	if (isRomSetDirectoryValid(romSetFilePath)) {
		printf("%s is a directory.\n", romSetFilePath);
	} else {
		printf("%s is not a directory.\n", romSetFilePath);
		return romSet; // Just return an empty ROM set for now.
	}
	// Get the files and such.
	filePaths = newRomPaths();
	filePaths = getFilePaths(romSetFilePath);
	printf("Okay, print the filenames.\n");
	printRomPaths(&filePaths);
	printf("Now, let's sort them.\n");
	sortRomSet(&filePaths, &romSet);
	return romSet;
}

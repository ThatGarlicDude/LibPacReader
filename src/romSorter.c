#include <dirent.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "romSet.h"

// Begins the process of sorting the ROMs in the directory.
void sortRomSet(DIR* directory, RomSet* romSet) {
	return;
}

/*
The ROMs in the Pac-Man and Puck-Man ROM sets have file extensions that
refer to where the ROMs are at in their respective PCBs. The only exception
is the Ms. Pac-Man ROM set, which contains the "boot" ROMs that have no
file extension. But nonetheless, we can use the file extensions for the
Pac-Man and Puck-Man ROM sets to our advantage when it comes to sorting them
alphabetically and numerically and laying  out the RomSet struct.
*/
const char* getFileExtension(const char fileName[]) {
	const char* period = strchr(fileName, '.');
	if (period == NULL) {
		return NULL; // If there's no period in the filename, just return null.
	} else {
		return ++period; // Return the string after the period.
	}
}

// Test.
FILE* getFiles(const char fileName[]) {
	DIR* directory = opendir(fileName);
	struct dirent* directoryEntry;
	printf("Preparing to print filenames.\n");
	while ((directoryEntry = readdir(directory)) != NULL) {
		// Ignore itself, and its parent directory.
		if (directoryEntry->d_name[0] == '.') {
			continue;
		}
		printf("File name is: %s\n", directoryEntry->d_name);
	}
	closedir(directory);
	return NULL;
}

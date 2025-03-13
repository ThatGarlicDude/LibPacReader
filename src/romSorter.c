#include <dirent.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "romPaths.h"
#include "romSet.h"

/*
The ROMs in the Pac-Man and Puck-Man ROM sets have file extensions that
refer to where the ROMs are at in their respective PCBs. The only exception
is the Ms. Pac-Man ROM set, which contains the "boot" ROMs that have no
file extension. But nonetheless, we can use the file extensions for the
Pac-Man and Puck-Man ROM sets to our advantage when it comes to sorting them
alphabetically and numerically and laying out the RomSet struct.
*/
const char* getFileExtension(const char fileName[]) {
	const char* period = strchr(fileName, '.');
	if (period == NULL) {
		return NULL; // If there's no period in the filename, just return null.
	} else {
		return ++period; // Return the string after the period.
	}
}

// Compares to see which file extension is greater than the other.
const char* compareFileExtensions(const char* extensionA, const char* extensionB) {
	int index = 0;
	while (extensionA[index] != '\0') {
		printf("Character %d of extension A is: %c\n", index, extensionA[index]);
		printf("Character %d of extension B is: %c\n", index, extensionB[index]);
		if (extensionA[index] > extensionB[index]) {
			return extensionA; // If extensionA is greater than B, return that.
		} else if (extensionA[index] < extensionB[index]) {
			return extensionB; // If not, return B instead.
		}
		index++;
	}
	return NULL; // If both the strings match, then just return null.
}

// Looks for a file whose extension is the lowest in terms of alphabetically and nurmerically.
const char* getLowestFileExtension(RomPaths* romPathPointer) {
	return NULL;
}

// Ditto, but with the highest alphabetically and numerically file extension.
const char* getHighestFileExtension(RomPaths* romPathPointer) {
	return NULL;
}

// Get the files included in the ROM set directory.
RomPaths getFilePaths(const char fileName[]) {
	DIR* directory = opendir(fileName);
	struct dirent* directoryEntry;
	RomPaths romPaths = newRomPaths();
	while ((directoryEntry = readdir(directory)) != NULL) {
		// Ignore itself, and its parent directory.
		if (directoryEntry->d_name[0] == '.') {
			continue;
		}
		addRomPath(&romPaths, directoryEntry->d_name);
	}
	closedir(directory);
	return romPaths;
}

// Begins sorting ROMs in the directory.
void sortRomSet(RomPaths* romPathPointer, RomSet* romSetPointer) {
	const char* extensionA = getFileExtension(romPathPointer->filePaths[0]);
	const char* extensionB = getFileExtension(romPathPointer->filePaths[1]);
	const char* highestExtension = compareFileExtensions(extensionA, extensionB);
	printf("Highest file extension here is: %s\n", highestExtension);
	return;
}

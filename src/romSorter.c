#include <dirent.h>
#include <stdio.h>
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
Pac-Man and Puck-Man ROM sets to our advantage by sorting them
alphabetically and numerically as the RomSet struct gets built.
*/
const char* getFileExtension(char* fileNamePointer[]) {
	return "";
}

#include <stdio.h>
#include <stdlib.h>

/*
In order to get a list of files in the ROM set directory, we need a
dynamic array where we will put the filepaths in there. This list
will then be sorted, and be put to the RomSet struct.
*/
typedef struct {
	char** filePaths;
	size_t size;
} RomPaths;

// Initiates the array.
RomPaths newRomPaths() {
	RomPaths romPaths;
	romPaths.size = 0;
	romPaths.filePaths = malloc(sizeof(char*) * romPaths.size);
	return romPaths;
};

// Adds a filepath to the dynamic array.
void addRomPath(RomPaths* romPathPointer, char* filePath) {
	romPathPointer->size++;
	romPathPointer->filePaths = realloc(romPathPointer->filePaths, sizeof(char*) * romPathPointer->size);
	romPathPointer->filePaths[romPathPointer->size - 1] = filePath;
};

// Free the array when we're done using it.
void freeRomPath(RomPaths* romPathPointer) {
	// Check if the pointer is null or not.
	if (romPathPointer == NULL) {
		return;
	}
	free(romPathPointer->filePaths);
	romPathPointer->size = 0;
};

// For debugging purposes.
void printRomPaths(RomPaths* romPathPointer) {
	for (size_t i = 0; i < romPathPointer->size; i++) {
		printf("%s\n", romPathPointer->filePaths[i]);
	}
};

// Gets the amount of filepaths in the struct.
size_t getRomPathSize(RomPaths* romPathPointer) {
	return romPathPointer->size;
};

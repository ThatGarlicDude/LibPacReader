#include <stdio.h>
#include <stdlib.h>

// Gets the current working directory.
const char* getCurrentDirectory(const char* directoryPath) {
	printf("Getting the working directory...\n");
	// If there is no specified directory path, then just get the working directory.
	if (directoryPath == NULL) {
		printf("Using the current directory instead.\n");
		directoryPath = "./";
	}
	printf("Using a custom working directory.\n");
	return realpath(directoryPath, NULL);
}

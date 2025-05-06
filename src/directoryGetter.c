#include <stdio.h>
#include <stdlib.h>

// Gets the current working directory.
char* getCurrentDirectory(char* directoryPath) {
	if (directoryPath == NULL) {
		directoryPath = "./";
	}
	return realpath(directoryPath, NULL);
}

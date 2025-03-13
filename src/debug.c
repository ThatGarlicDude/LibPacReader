#include <stdio.h>
#include "romPaths.h"
#include "romReader.h"
#include "romSet.h"
#include "romSorter.h"
#include "romVersion.h"

void test() {
	RomPaths romPath = newRomPaths();
	printf("Size of the romPaths is: %ld\n", romPath.size);
	printRomPaths(&romPath); // Print this before adding anything.
	printf("Let's add some new filepaths.\n");
	addRomPath(&romPath, "test");
	printRomPaths(&romPath);
	printf("Now let's add more...\n");
	addRomPath(&romPath, "garlicdude");
	printf("Now let's print it out.\n");
	printRomPaths(&romPath);
	printf("Awesome, now let's free the array.\n");
	freeRomPath(&romPath);
	printf("Alright, now let's print the array.\n");
	printRomPaths(&romPath);
}

// Main function.
int main(int argc, char* argv[]) {
	test();
	return 0;
	/* Due to copyright reasons, you need to tell the program where
	the ROM set directory is at.*/
	if (argc == 1) {
		printf("You need a ROM set directory to continue.\n");
		return -1;
	}
	RomSet romDir = readRomSet(argv[1]);
	return 0;
}

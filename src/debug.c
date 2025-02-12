#include <stdio.h>
#include "romReader.h"
#include "romSet.h"
#include "romVersion.h"

int main(int argc, char *argv[]) {
	/* Due to copyright reasons, you need to tell the program where
	the ROM set directory is at.*/
	if (argc == 1) {
		printf("You need a ROM set directory to continue.\n");
		return -1;
	}
	RomSet romDir = readRomSetFromPath(&argv[1]);
	return 0;
}

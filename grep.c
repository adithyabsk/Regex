#include <stdlib.h>
#include <stdio.h> 	/* for printf */
#include <string.h>	/* for strlen */
#include <stdbool.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <err.h>
#include <fts.h>

#include "io.h"

// Grep Wildcard functionality
// DataStructures Final: Dr. Morrison

// AUTHORS: Alexander Allen
//	       Adithya Balaji

// Change Log:
// 12:00pm 2-7-17: Initial Commit with base structure (Alexander)
// 3:30pm 2-7-17: Read from standard in, add to data structre is broken (Alexander & Adithya)

static int ptree(char * const argv[]);

int main(int argc, char **argv)
{
	bool shouldReadStdIn = true;
	char search[100];
	if (argc == 1) exit(0); // Add some error message
	else if (argc == 2); // Do nothing
	else if (argc > 2 && !strcmp("-r", argv[2])) shouldReadStdIn = false;
	else exit(0); // Add some error message

	strcpy (search, argv[1]);
	Array lines;

	if (!shouldReadStdIn)
	{
		//search file system
	}
	else
	{
		puts(search);
		// Read from stdIn
		initArray(&lines, 1);
		readStdIn(&lines);
		// printArray(&lines);
		grepCheck(&lines, search);
		freeArray(&lines);
	}
	return 0;
}
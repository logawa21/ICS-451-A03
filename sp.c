#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create a pointer p and poin it to the first character of the argument

// for each string:
// find out the length L of the string that p refers to (not including "/")
// use malloc to allocate buffer B of length L+1
// check the value returned by malloc is not NULL. If it is print message and exit

// this isn't needed but it is a refernce on what goes where
// for the strtok (string to split, what character defines where we split)
//char *strtok(char *s, const char *delim);

int main (int argc, char ** argv) {

	if (argc != 2) {
		//not sure about this wording....
		printf("Error message.\nYou need to have one argument.");
		exit(0);
	}
	// 
	if (argc == 2) {

		// used this website as a reference for splitting strings
		// into tokens with the strtok function
		// http://www.tutorialspoint.com/ansi_c/c_strtok.htm
		char * split;

		//printf("Splitting string \"%s\" into tokens:\n", argv[1]);
		split = strtok (argv[1], "/");

		while (split != NULL) {

			// used this site as reference for (unsigned)strlen to
			// get the string length + 1
			// http://www.cplusplus.com/reference/cstring/strlen/
			printf("%s (%u)\n", split, (unsigned)strlen(split) + 1);
			split = strtok (NULL, "/");
		}

		//Tested if we were able to get the command line argument
		//printf("Testing.\nYou wrote: %s\n", argv[1]);
	}
}

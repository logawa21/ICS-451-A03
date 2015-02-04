#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create a pointer p and poin it to the first character of the argument

// for each string:
// find out the length L of the string that p refers to (not including "/")
// use malloc to allocate buffer B of length L+1
// check the value returned by malloc is not NULL. If it is print message and exit

// this isn't needed but it is a reference on what goes where
// for the strtok (string to split, what character defines where we split)
//char *strtok(char *s, const char *delim);

int main (int argc, char ** argv) {
    
    char *        p; //pointer
    char *        B; //buffer
    unsigned long L; //length of buffer
    
    
    //check valid number of arguments [2]
    if (argc != 2) {
        printf("This program take one argument, a set of strings seperated by '/'.\n");
        exit(0);
    }
    
    // set pointer to point to the first string in the set
    p = strtok (argv[1], "/");
    
    //loop through all strings in the set
    while(p != NULL){
        
        //get length of p
        L = strlen(p);
        
        //create memory to store p in buffer
        B = malloc(sizeof(char) * (L+1));
        
        //check to see if memory was allocated to buffer
        if (B == NULL){
            printf("Could not allocate memory to the buffer.");
            exit(1);
        }
        
        //copy p to buffer and null character
        snprintf(B, L+1, "%s", p);
        
        //print the current string and length
        printf("%s (%lu)\n", B, strlen(B) + 1);
        
        //free buffer memory
        free(B);
        
        //set pointer to next string in the set
        p = strtok (NULL, "/");
    }
}

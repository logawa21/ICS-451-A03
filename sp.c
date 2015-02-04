//
//  Structs, Pointers, and Buffers
//
//  Created by Lauren Ogawa on 2/2/15.
//  Copyright (c) 2015 Lauren Ogawa. All rights reserved.
//

#include <stdio.h>
#include <netinet/in.h>  /* gives htons and friends */

struct hw3 {
  char 	x;
  char 	y;
  short z;
  int 	w;
};

char buffer [] = { 0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0 };
//char buffer [] = {0x89};

//combining the struct with the buffer array
struct hw3 * sp = (struct hw3 *) buffer;

void print_buffer (char * buffer, int num_bytes) {

	// prints all the bytes (in hex) in the buffer
	for(int i = 0; i<num_bytes; i++)
		//printf("%#x ", buffer[i] & 0xff);
		printf("%02x ", buffer[i] & 0xff);
	printf("\n");
}

// takes a single parameter, a pointer to struct hw3
//sp->x is 0x12, sp->y is 0x34, sp->z is 0x5678, sp->w is 0x9abcdef0
void print_struct (struct hw3 * sp) {
	printf("sp->x is %#x\n", sp->x & 0xff);
	printf("sp->y is %#x\n", sp->y & 0xff);
	printf("sp->z is %#x\n", ntohs(sp->z));
	printf("sp->w is %#x\n", ntohl(sp->w));
}

int main(){

	// get the size of the buffer array
	int num_bytes = sizeof(buffer);

	//call function print_buffer()
	print_buffer(&buffer[0], num_bytes);

	// declare hw1 of type hw3
	struct hw3 hw1;

	print_struct(&hw1);

	//printf("test %#x\n", hw1.x);
	//printf("%lu\n", sizeof(hw1)/2);

	return 0;
}

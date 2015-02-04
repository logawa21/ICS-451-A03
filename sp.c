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

struct hw3 * sp = (struct hw3 *) buffer;

void print_buffer (char * buffer, int num_bytes) {
    int i;
    // prints all the bytes (in hex) in the buffer
    for(i = 0; i<num_bytes; i++)
        printf("%02x ", buffer[i] & 0xff);
    
    printf("\n");
}

// takes a single parameter, a pointer to struct hw3
//sp->x is 0x12, sp->y is 0x34, sp->z is 0x5678, sp->w is 0x9abcdef0
void print_struct (struct hw3 * sp) {
    
    printf("sp->x is %02x, ", sp->x & 0xff);
    printf("sp->x is %02x, ", sp->y & 0xff);
    printf("sp->z is %x, ", htons(sp->z));
    printf("sp->w is %x  ", htonl(sp->w));
    printf("\n");
}

int main(){
    
    // get the size of the buffer array
    int num_bytes_buf = sizeof(buffer);
    int num_bytes_sp  = sizeof(*sp);
    
    //call function print_buffer()
    print_buffer(&buffer[0], num_bytes_buf);
    print_struct((struct hw3 *)buffer);
    
    print_buffer((char *)sp, num_bytes_sp);
    print_struct(sp);
    
    sp->x = 0x77;
    sp->y = 0x92;
    sp->z = ntohs(0x4389);
    sp->w = ntohl(0xabc89032);
    
    print_buffer((char *)sp, num_bytes_sp);
    print_struct(sp);
    
    return 0;
}

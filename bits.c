//
//  main.c
//  Bits
//
//  Created by Joshua Weldon on 2/2/15.
//  Copyright (c) 2015 Joshua Weldon. All rights reserved.
//

#include <stdio.h>

unsigned int set_bits (unsigned int value){
    
    unsigned int maxByteValue = 0xff;
    unsigned int leadingBits  = 0xc0;
    
    value = value & maxByteValue; //remove large bits
    value = value | leadingBits; //set leading bits
    
    printf("0x%x\n", value);
    
    return value;
}

unsigned int combine_bits (int top, int middle, int low){
    
    unsigned int value = 0;
    
    int maxTopValue    = 0x3;
    int maxMiddleValue = 0xf;
    int maxLowValue    = 0x3ff;
    
    top    = top    & maxTopValue;
    middle = middle & maxMiddleValue;
    low    = low    & maxLowValue;
    
    value = value + top;
    
    value = value << 4;
    value = value + middle;
    
    value = value << 10;
    value = value + low;
    
    printf("0x%x\n",value);
    
    return value;
}


int main(int argc, const char * argv[]) {
  
    //
    // Test the method set_bits
    //
    
    printf("Test 0x100 => c0\n");
    set_bits(0x100);
    
    
    printf("Test 0x5 => c5\n");
    set_bits(0x5);
    
    printf("Test 0x72 => f2\n");
    set_bits(0x72);
    
    printf("Test 0xc5 => c5\n");
    set_bits(0xc5);
    
    //
    // Test the method combine_bits
    //
    
    printf("Test 0x2, 0x5, 0x123 => 9523\n");
    combine_bits(0x2, 0x5, 0x123);
    
    printf("Test 0x1, 0x9, 0x321 => 6721\n");
    combine_bits(0x1, 0x9, 0x321);
    
    return 0;
}

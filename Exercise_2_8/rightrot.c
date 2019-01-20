#include <stdio.h>

/*
Exercise 2-8: Write a function rightrot(x, n) that returns the value of the integer x rotated to the right by n bit positions
*/

unsigned int rightrot(unsigned int x, int n) {
    int numberOfBits, i;
    unsigned int bitCheck, leftmostBit;
    
    /* First, check to see how many bits are in unsigned integer value */
    bitCheck = ~0;
    numberOfBits = 0;
    while (bitCheck > 0) {
        bitCheck = bitCheck >> 1;
        numberOfBits++;
    }
    /* Next, initialize leftmostBit by shifting a one bit from the position 0 (1) to far left position */
    leftmostBit = 1 << (numberOfBits - 1);

    for (i = 0; i < n; i++) {
        if (x & 1 == 1) {
            /* x's 0 position bit is 1, shift it and then add a one to x's leftmost bit to properly "rotate" it */
            x = ((x >> 1) | leftmostBit);
        } else {
            /* x's 0 position is 0, just shift it*/
            x = x >> 1;
        }
    }
    return x;
}

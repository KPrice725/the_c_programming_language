#include <stdio.h>

/*
Exercise 2-7: Write a function invert(x, p, n) that returns x
with the n bits that begin at position p inverted
(i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/

unsigned invert(unsigned int x, int p, int n) {
    unsigned int zeroedX, invertedX;

    /*
    zeroedX: Move the target bit range in x that is to be modified to the right-most side, then set the rest of the bits to 0.
    Next, shift the bits back to their original position
    Set target bits in x to zero using ^
    */
    zeroedX = (((x >> (p + 1 - n)) & ~(~0 << n)) << (p + 1 - n)) ^ x;

    /*
    invertedX: Invert x and move target bit range in x that is to be inserted into the zeroed x to the right-most side, then set the rest of the bits to 0.
    Next, shift the bits to position that the zeroed x bit range will be modified at
    */
    invertedX = ((~x >> (p + 1 - n)) & ~(~0 << n)) << (p + 1 - n);

    /* Use | to turn on bits in zeroed x range to match the bits in inverted x range */
    return zeroedX | invertedX;
}

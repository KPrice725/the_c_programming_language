#include <stdio.h>

/*
Exercise 2-6: Write a function setbits(x, p, n, y)
that returns x with the n bits that begin at position p
set to the rightmost n bits of y, leaving the other bits unchanged.
*/

unsigned setbits(unsigned int x, int p, int n, unsigned int y) {
    unsigned int modX, modY;

    /*
    modX: Move the target bit range in x that is to be modified to the right-most side, then set the rest of the bits to 0.
    Next, shift the bits back to their original position
    Set target bits in x to zero using ^
    */
    modX = (((x >> (p + 1 - n)) & ~(~0 << n)) << (p + 1 - n)) ^ x;

    /*
    modY: Set the all bits to the left of the right-most n bits in y to 0.
    Next, shift the bits to position that x bit range will be modified at
    */
    modY = (y & ~(~0 << n)) << (p + 1 - n);

    /* Use | to set turn on bits in x range to match the bits in y range */
    return modX | modY;
}

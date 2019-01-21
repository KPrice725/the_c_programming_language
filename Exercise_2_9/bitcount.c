#include <stdio.h>

/*
Exercise 2-9: In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
Explain why.  Use this observation to write a faster version of bitcount.
*/

/*
bitcount: In the expression (x - 1), the result is that the rightmost 1-bit from the x value will always be set to 0, 
with the bits to the right of that bit all set to 1. When taking that expression and inserting into x &= (x - 1), 
since the rightmost bit is set to 0, and the rightmost bits are all set to 1, all those bits will result in being set to 0 
with the & operator. Each time this is run, this removes the rightmost bit of x until x == 0.  
This is faster than the x >>= 1 method, since the loop only has to run as many times are there are 1-bits in the x argument,
whereas with x >>= 1, the loop has to run as many times as the position index value of leftmost 1-bit in the x argument.
*/

int bitcount(unsigned int x) {
    int b;

    for (b = 0; x != 0; x &= (x - 1)) {
        b++;
    }
    
    return b;
}

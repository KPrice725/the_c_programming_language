#include <stdio.h>
#include <limits.h>

void printSignedCharRange();
void printUnsignedCharRange();
void printSignedShortRange();
void printUnsignedShortRange();
void printSignedIntRange();
void printUnsignedIntRange();
void printSignedLongRange();
void printUnsignedLongRange();

/*
Exercise 2-1: Write a program to determine the ranges of char, short, int, and long variables,
both signed and unsigned, by printing appropriate values from standard headers and by direct computation.
Harder if you compute them: determine the ranges of the various floating-point types.
*/

/*
Calculating Unsigned Variables: Assigning ~0 to an unsigned variable inverts all bits from 0 to 1, representing the maximum value.
The minimum value of an unsigned variable is always 0.
*/

/*
Calculating Signed Variables: Assigning ~0 to an unsigned variable inverts all bits from 0 to 1.
Since the first bit of a signed variable represents if the value is positive or negative,
by shifting the bits to the right by 1 (x >> 1) and casting this result to the signed equivalent variable,
the maximum signed variable value is extracted.
The minimum value of a signed variable can be acquired by inverting the shifted unsigned value above (~(x >> 1))
and casting it to the equivalent signed variable.  Inverting this value assigns the first bit to 1 and the rest to 0,
representing the lowest negative value.
*/
int main() {

	printSignedCharRange();
	printUnsignedCharRange();
	printSignedShortRange();
	printUnsignedShortRange();
	printSignedIntRange();
	printUnsignedIntRange();
	printSignedLongRange();
	printUnsignedLongRange();

	return 0;
}

void printSignedCharRange() {

	printf("Standard Library\tSigned Char Max: %d\t\tSigned Char Min: %d\n", SCHAR_MAX, SCHAR_MIN);

	unsigned char uc;
	uc = ~0;
	printf("Computed\t\tSigned Char Max: %d\t\tSigned Char Min: %d\n", (signed char) (uc >> 1), (signed char) ~(uc >> 1));
}

void printUnsignedCharRange() {

	printf("Standard Library\tUnsigned Char Max: %d\t\tUnsigned Char Min: %d\n", UCHAR_MAX, 0);

	unsigned char uc;
	uc = ~0;
	printf("Computed\t\tUnsigned Char Max: %d\t\tUnsigned Char Min: %d\n", uc, 0);
}

void printSignedShortRange() {

	printf("Standard Library\tSigned Short Max: %d\t\tSigned Short Min: %d\n", SHRT_MAX, SHRT_MIN);

	unsigned short us;
	us = ~0;
	printf("Computed\t\tSigned Short Max: %d\t\tSigned Short Min: %d\n", (signed short) (us >> 1), (signed short) ~(us >> 1));
}

void printUnsignedShortRange() {

	printf("Standard Library\tUnsigned Short Max: %d\tUnsigned Short Min: %d\n", USHRT_MAX, 0);

	unsigned short us;
	us = ~0;
	printf("Computed\t\tUnsigned Short Max: %d\tUnsigned Short Min: %d\n", us, 0);
}

void printSignedIntRange() {

	printf("Standard Library\tSigned Int Max: %d\tSigned Int Min: %d\n", INT_MAX, INT_MIN);

	unsigned int ui;
	ui = ~0;
	printf("Computed\t\tSigned Int Max: %d\tSigned Int Min: %d\n", (signed int) (ui >> 1), (signed int) ~(ui >> 1));
}

void printUnsignedIntRange() {

	printf("Standard Library\tUnsigned Int Max: %u\tUnsigned Int Min: %u\n", UINT_MAX, 0);

	unsigned int ui;
	ui = ~0;
	printf("Computed\t\tUnsigned Int Max: %u\tUnsigned Int Min: %u\n", ui, 0);
}

void printSignedLongRange() {

	printf("Standard Library\tSigned Long Max: %d\tSigned Long Min: %d\n", LONG_MAX, LONG_MIN);

	unsigned long ul;
	ul = ~0;
	printf("Computed\t\tSigned Long Max: %d\tSigned Long Min: %d\n", (signed long) (ul >> 1), (signed long) ~(ul >> 1));
}

void printUnsignedLongRange() {

	printf("Standard Library\tUnsigned Long Max: %u\tUnsigned Long Min: %u\n", ULONG_MAX, 0);

	unsigned long ul;
	ul = ~0;
	printf("Computed\t\tUnsigned Long Max: %u\tUnsigned Long Min: %u\n", ul, 0);
}

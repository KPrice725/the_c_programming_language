#include <stdio.h>
#include <string.h>

/*
Exercise 3-4: In a two's complement number representation, our version of itoa does not handle the largest negative number,
that is, the value of n equal to -(2^(wordsize-1)). Explain why not. Modify it to print that value correctly,
regardless of the machine on which it runs.
*/

/*
In two's complement number representation, a negative value is acquired by inverting the bits of the positive value and adding 1.
The largest negative number is represented by 1000 0000 0000 0000 0000 0000 0000 0000 (0x80000000).
To see what this number is a negative of, we invert the bits and add one, resulting in 1000 0000 0000 0000 0000 0000 0000 0000
The n = -n statement in the original itoa function does not yield a positive value, thus corrupting the value assigned to s[0] in the do while loop.
Instead, assign 1 to sign for positive, or -1 to sign for negative.
Then in the do while loop, use the sign value to change n to a positive value, in the case of negative values.
Finally, modify the while condition so that it's not checking for a positive value, but simply a non-zero value.
*/

void reverse(char s[]);
void itoa(int n, char s[]);
void itoaKP(int n, char s[]);

void reverse(char s[]) {
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[]) {
	int i, sign;
	if ((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}

void itoaKP(int n, char s[]) {
	int i;
	int sign = (n < 0) ? -1 : 1;

	i = 0;
	do {
		s[i++] = sign * (n % 10) + '0';
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

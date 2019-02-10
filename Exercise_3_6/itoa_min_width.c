#include <stdio.h>

/*
Exercise 3-6: Write a version of itoa that accepts three arguments instead of two.
The third argument is a minimum field width; the converted number must be
padded with blanks on the left if necessary to make it wide enough.
*/

void itoa(int n, char s[], int minWidth);
void reverse(char s[]);

void itoa(int n, char s[], int minWidth) {
	int i = 0;
	int sign = (n < 0) ? -1 : 1;

	do {
		s[i++] = sign * (n % 10) + '0';
	} while ((n /= 10) != 0);
	if (sign < 0) {
        s[i++] = '-';
	}
	while (i < minWidth) {
        s[i++] = ' ';
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

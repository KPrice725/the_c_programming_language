#include <stdio.h>
#define DECIMAL 10
#define HEX	16
#define OCTAL	8
#define BINARY  1

void itob(int number, char output[], char base);
void itoa_decimal(int n, char s[]);
void itoa_octal(int n, char s[]);
void itoa_hex(int n, char s[]);
void itoa_binary(int n, char s[]);
void reverse(char s[]);

void itob(int number, char output[], char base) {

	switch (base) {

	case BINARY:
        	itoa_binary(number, output);
		break;

	case OCTAL:
        	itoa_octal(number, output);
		break;

	case DECIMAL:
		itoa_decimal(number, output);
		break;

	case HEX:
		itoa_hex(number, output);
		break;

	default:
		break;
	}
}

void itoa_decimal(int n, char s[]) {
	int i = 0;
	int sign = (n < 0) ? -1 : 1;

	do {
		s[i++] = sign * (n % 10) + '0';
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void itoa_octal(int n, char s[]) {
	int i = 0;
	int sign = (n < 0) ? -1 : 1;

    	do {
        	s[i++] = sign * (n % 8) + '0';
    	} while ((n /= 8) != 0);

	if (sign == -1) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}

void itoa_hex(int n, char s[]) {
    	int unsigned un = n;
	int i = 0;

	do {
        	int unsigned value = un % 16;
        	s[i++] = (value > 9) ? (value - 10 + 'A') : (value + '0');
	} while ((un /= 16) != 0);

	s[i] = '\0';
	reverse(s);

}

void itoa_binary(int n, char s[]) {

  	int unsigned un = n;
	int i = 0;

	do {
        	int unsigned value = un % 2;
        	s[i++] = (value == 1) ? '1' : '0';
	} while ((un /= 2) != 0);

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

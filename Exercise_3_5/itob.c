#include <stdio.h>
#define DECIMAL 10
#define HEX		16
#define OCTAL	8

void itob(int number, char output[], char base);
void itoa_decimal(int n, char s[]);
void itoa_octal(int n, char s[]);
void itoa_hex(int n, char s[]);
void reverse(char s[]);

int main(void) {

	char result[sizeof(int) * 8 + 1];
	int input1 = 0x9D02AAB4;
	int input2 = 0xF2A76A;
	int input3 = 0x992718AB;

//	itob(input, result, DECIMAL);
//
//	printf("%s\n", result);

	itob(input1, result, HEX);

	printf("%s\n", result);

	itob(input2, result, HEX);

	printf("%s\n", result);

	itob(input3, result, HEX);

	printf("%s\n", result);

	return 0;
}

void itob(int number, char output[], char base) {

	switch (base) {

	case 1:

		break;

	case OCTAL:

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
}

void itoa_hex(int n, char s[]) {
	int i = 0;
	int sign = (n < 0) ? -1 : 1;
	int targetByte;
	if (sign == 1) {
		targetByte = 0xF;
	} else {
		targetByte = 0xF0000000;
	}

	do {
		int unsigned byte = n & targetByte;
		if (sign == -1) {
			byte >>= 28;
		}
		switch (byte) {
		case 0x0:
			s[i++] = '0';
			break;
		case 0x1:
			s[i++] = '1';
			break;
		case 0x2:
			s[i++] = '2';
			break;
		case 0x3:
			s[i++] = '3';
			break;
		case 0x4:
			s[i++] = '4';
			break;
		case 0x5:
			s[i++] = '5';
			break;
		case 0x6:
			s[i++] = '6';
			break;
		case 0x7:
			s[i++] = '7';
			break;
		case 0x8:
			s[i++] = '8';
			break;
		case 0x9:
			s[i++] = '9';
			break;
		case 0xA:
			s[i++] = 'A';
			break;
		case 0xB:
			s[i++] = 'B';
			break;
		case 0xC:
			s[i++] = 'C';
			break;
		case 0xD:
			s[i++] = 'D';
			break;
		case 0xE:
			s[i++] = 'E';
			break;
		case 0xF:
			s[i++] = 'F';
			break;
		default:
			break;
		}
		if (sign == 1) {
			n >>= 4;
		} else {
			n <<= 4;
		}
	} while (n != 0);
	s[i] = '\0';
	if (sign == 1) {
		reverse(s);
	}

}

void reverse(char s[]) {
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

}

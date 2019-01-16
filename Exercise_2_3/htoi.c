#include <string.h>
#include <ctype.h>
#include <math.h>

/*
Exercise 2-3: Write a function htoi(s), which converts a string of hexadecimal digits 
(including an optional 0x or 0X) into its equivalent integer value.
The allowable digits are 0 through 9, a through f, and A through F
*/

int htoi(char s[]) {
	int i, exp, result;
	exp = result = 0;

	for (i = strlen(s) - 1; i >= 0 && (isdigit(s[i]) || (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f')); --i) {
		if (isdigit(s[i])) {
			result = result + pow(16, exp) * (s[i] - '0');
		} else {
			result = result + pow(16, exp) * ((tolower(s[i]) - 'a') + 10);
		}
		++exp;
	}

	return result;
}

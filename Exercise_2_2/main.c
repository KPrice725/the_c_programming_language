#include <stdio.h>

/*
for (i = 0; i < lim -1 && (c = getchar()) != '\n' && c != EOF; ++i) {
	s[i] = c;
}
*/

/*
Exercise 2-2: Write a loop equivalent to the for loop above without using && or ||
*/

int main() {

	int lim, i, c;

	lim = 1000;
	i = 0;

	char s[lim];

	while (i < lim - 1) {
		c = getchar();
		if (c == '\n') {
			break;
		} else if (c == EOF) {
			break;
		} else {
			s[i] = c;
			++i;
		}
	}
	s[i] = '\0';

	printf("%s\n", s);

	return 0;
}

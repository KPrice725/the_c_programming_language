#include <stdio.h>
#include <ctype.h>
#define MAX_LENGTH 100

/*
 Exercise 3-3. Write a function expand (s 1, s2) that expands shorthand notations like a - z in the string s1
 into the equivalent complete list abc ... xyz in s2. Allow for letters of either case and digits,
 and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
 */

void expand(char s1[], char s2[]) {
	int i, j, c1, c2;
	i = j = c1 = c2 = 0;
	while (s1[i] != '\0' && j < MAX_LENGTH) {
		s2[j++] = s1[i++];
		if (s1[i] == '-' && (isalnum(s1[i + 1]) && isalnum(s1[i - 1]))) {
			c1 = s1[i - 1];
			c2 = s1[++i];
			while ((j < MAX_LENGTH) && (c1 < c2)) {
				s2[j++] = ++c1;
			}
			i++;
		}
	}
	s2[j] = '\0';
}

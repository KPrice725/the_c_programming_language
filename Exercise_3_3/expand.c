#include <stdio.h>
#include <ctype.h>
#define MAX_LENGTH 100

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

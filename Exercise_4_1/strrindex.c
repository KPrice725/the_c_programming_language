#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

char pattern[] = "ould";

/*
Exercise 4-1: Write the function strrindex(s, t),
which returns the position of the rightmost occurrence of t in s,
or -1 if there is none.
*/

int getLine(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
			;
		}
		if (k > 0 && t[k] == '\0') {
			return i;
		}
	}
	return -1;
}
/* My strrindex also includes a sLength parameter, since we already calculate the length of s in getLine(), 
there's no need to calculate that again.
Essentially reverse the original strindex, iterating right to left through s and t until a match is found.  
If a match is found, return j, since that's the starting position of the pattern in the s array.  Otherwise, return -1.
*/
int strrindex(char s[], int sLength, char t[])
{
	int i, j, k;
	int tLength = strlen(t);
	for (i = sLength - 1; i > 0; i--) {
		for (j = i, k = tLength - 1; k > 0 && s[j] == t[k]; j--, k--) {
			;
		}
		if (k == 0 && s[j] == t[k]) {
			return j;
		}
	}
	return -1;
}

int main(void) {

	char line[MAXLINE];
	int found = 0;
	int lineLength, returnIndex;

	while ((lineLength = getLine(line, MAXLINE)) > 0) {
		if ((returnIndex = strrindex(line, lineLength, pattern)) >= 0) {
			printf("%s\n%d\n", line, returnIndex);
			found++;
		}
	}
	return found;
}

#include <stdio.h>

#define MAX_CHARACTERS 0xFF		/* 256-Character ASCII Set */
enum boolean {FALSE, TRUE};

/*
Exercise 2-4: Write an alternate version of squeeze(s1, s2) that deletes each character in s1 that matches any character in the string s2.
*/
void squeeze(char s1[], const char s2[]);

/*
squeeze: create a characters array with each value initialized to FALSE,
then iterate through s2 string, setting the value of the characters array at the s2 char's index value to TRUE.
Then iterate through the s1 string, checking to see if the value in the characters array is TRUE,
skipping over it, if so.
*/
void squeeze(char s1[], const char s2[]) {

	int characters[MAX_CHARACTERS], i, j;
	for (i = 0; i < MAX_CHARACTERS; ++i) {
		characters[i] = FALSE;
	}

	for (i = 0; s2[i] != '\0'; ++i) {
		characters[s2[i]] = TRUE;
	}

	for (i = j = 0; s1[i] != '\0'; ++i) {
		if (characters[s1[i]] == FALSE) {
			s1[j++] = s1[i];
		}
	}
	s1[j] = '\0';
}

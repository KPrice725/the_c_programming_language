#include <stdio.h>

#define MAX_CHARACTERS 0xFF		/* 256-Character ASCII Set */
enum boolean {FALSE, TRUE};

int any(const char s1[], const char s2[]);

/*
Exercise 2-5: Write the function any(s1, s2), which returns the first location in the string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the location.)
*/

/*
any: create a characters array with each value initialized to FALSE,
then iterate through s2 string, setting the value of the characters array at the s2 char's index value to TRUE.
Then iterate through the s1 string, checking to see if the value in the characters array is TRUE.
Return the index value of the first TRUE result.
*/
int any(const char s1[], const char s2[]) {

	int characters[MAX_CHARACTERS], i;
		for (i = 0; i < MAX_CHARACTERS; ++i) {
			characters[i] = FALSE;
		}

		for (i = 0; s2[i] != '\0'; ++i) {
			characters[s2[i]] = TRUE;
		}

		for (i = 0; s1[i] != '\0'; ++i) {
			if (characters[s1[i]] == TRUE) {
				return i;
			}
		}

	return -1;
}

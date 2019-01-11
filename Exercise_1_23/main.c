#include <stdio.h>

#define MAX_LENGTH 10000

/* Exercise 1-23: Write a program to remove all comments from a C program.
 Don't forget to handle quoted strings and character constants properly.
 C comments do not nest.
*/

// single line comment - exits after '\n' character
/* multiline comment - exits after the exit token is found */

int getLine(char line[], int maxLength);				/* receive and process user input text */
void removeSingleLineComment(char line[], int index);	/* skips user input until end of single line comment */
void removeMultiLineComment();							/* skips user input until end of multi line comment */

int main() {

	int length;
	char output[MAX_LENGTH];

	while ((length = getLine(output, MAX_LENGTH)) > 0) {
		printf("%s\n", output);
	}

	return 0;
}

int getLine(char line[], int maxLength) {

	int i, c;

	for (i = 0; (c = getchar()) != EOF; ++i) {
		if (i < maxLength - 1) {
			if (c == '/') {
				if ((c = getchar()) == '/') {
					removeSingleLineComment(line, i);
				} else if (c == '*') {
					removeMultiLineComment();
					--i;
				} else {
					line[i] = '/';
					++i;
					if (i == maxLength - 1) {
						break;
					}
					line[i] = c;
				}
			} else if (c == '"') { /* handle double quotes */
				line[i] = c;
				++i;
				while ((c = getchar()) != '"' && i != maxLength - 1) {
					line[i] = c;
					++i;
				}
				if (i == maxLength - 1) {
					break;
				}
				line[i] = c;
			} else if (c == '\'') { /* handle single quotes */
				line[i] = c;
				++i;
				while ((c = getchar()) != '\'' && i != maxLength - 1) {
					if (c == '\\') { /* handle escape character backslash */
						line[i] = c;
						++i;
						if (i != maxLength - 1) {
							c = getchar();
							line[i] = c;
							++i;
						}
					} else {
						line[i] = c;
						++i;
					}
				}
				if (i == maxLength - 1) {
					break;
				}
				line[i] = c;
			} else {
				line[i] = c;
			}
		}
	}

	if (i < maxLength - 1) {
		line[i] = '\0';
	} else {
	    line[maxLength - 1] = '\0';
	}

	return i;

}

void removeSingleLineComment(char line[], int i) {
	char c;
	while ((c = getchar()) != EOF && c != '\n');
	if (c == '\n') {
		line[i] = c;
	}
}

void removeMultiLineComment() {
	char c;
	while ((c = getchar()) != EOF) {
		while (c == '*') {
			if ((c = getchar()) == '/') {
				return;
			}
		}
	}
}

#include <stdio.h>

/*
Exercise 1-24: Write a program to check a C program for rudimentary syntax errors, like unbalanced parentheses, brackets and braces.
Don't forget about quotes, both single and double, escape sequences, and comments.
*/

int parenthesesCount, bracketsCount, bracesCount, lineCount, totalErrorCount;

void checkProgram();				/* receive and process user input text */
void checkDoubleQuotes();			/* check to see if double quote is handled properly */
void checkSingleQuotes();			/* check to see if single quote is handled properly */
void checkMultilineComment();		/* check to see if multiline comment is handled properly */
void skipSinglelineComment();		/* skip over single line comment line*/
void checkBracket(int c);			/* check to see if char is one of the bracket types, and maintain current open count*/

int main() {

	extern int parenthesesCount, bracketsCount, bracesCount, lineCount, totalErrorCount;

	parenthesesCount = bracketsCount = bracesCount = totalErrorCount = 0;

	lineCount = 1;

	checkProgram();

	return 0;
}

void checkProgram() {

	int c;
	extern int parenthesesCount, bracketsCount, bracesCount, lineCount, totalErrorCount;

	while ((c = getchar()) != EOF) {
		if (c == '"') {
			checkDoubleQuotes();
		} else if (c == '/') {
			if ((c = getchar()) != EOF) {
				if (c == '*') {
					checkMultilineComment();
				} else if (c == '/') {
					skipSinglelineComment();
				}
			} else {
				break;
			}
		} else if (c == '\'') {
			checkSingleQuotes();
		} else if (c == '\n') {
			++lineCount;
		} else {
			checkBracket(c);
		}
		if (c == EOF) {
			break;
		}
	}

	if (parenthesesCount != 0) {
		printf("Parentheses Error; Total left open: %d\n", parenthesesCount);
		++totalErrorCount;
	}
	if (bracketsCount != 0) {
		printf("Brackets Error; Total left open: %d\n", bracketsCount);
		++totalErrorCount;
	}
	if (bracesCount != 0) {
		printf("Braces Error; Total left open: %d\n", bracesCount);
		++totalErrorCount;
	}
	printf("Total Error Count: %d\n", totalErrorCount);
}

void checkDoubleQuotes() {
	int c;
	extern int lineCount, totalErrorCount;
	while ((c = getchar()) != EOF) {
		if (c == '\\') {				/* this is an escape character, skip the next character */
			getchar();
		} else if (c == '"') {			/* found the closing double quote! */
			break;
		}
	}
	if (c == EOF) {
		printf("Double Quote Syntax Error on Line %d\n", lineCount);
		++totalErrorCount;
	}
}

void checkSingleQuotes() {
	int c;
	extern int lineCount, totalErrorCount;
	if ((c = getchar()) != EOF && c == '\\') {
		getchar();						/* this is an escape character, skip the next character */
	}
	if ((c = getchar()) != '\'') {
		printf("Single Quote Syntax Error on Line %d\n", lineCount);
		++totalErrorCount;
		while ((c = getchar()) != '\'' && c != EOF);
	}
}

void checkMultilineComment() {
	int c;
	extern int lineCount, totalErrorCount;
	while ((c = getchar()) != EOF) {
		if (c == '*') {
			if ((c = getchar()) == '/') {
				return;
			}
		}
		if (c == '\n') {
			++lineCount;
		}
	}
	if (c == EOF) {
		printf("Multi-line Comment Syntax Error on Line %d\n", lineCount);
		++totalErrorCount;
	}
}

void skipSinglelineComment() {
	int c;
	extern int lineCount, totalErrorCount;
	while ((c = getchar()) != EOF && c != '\n');
	if (c == '\n') {
		++lineCount;
	}
}

void checkBracket(int c) {
	extern int parenthesesCount, bracketsCount, bracesCount, lineCount;

	if (c == '(') {
		++parenthesesCount;
	} else if (c == ')') {
		--parenthesesCount;
	} else if (c == '[') {
		++bracketsCount;
	} else if (c == ']') {
		--bracketsCount;
	} else if (c == '{') {
		++bracesCount;
	} else if (c == '}') {
		--bracesCount;
	}
}

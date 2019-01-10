#include <stdio.h>

#define MAX_LINE 1000                           /* Maximum length of output */
#define TAB_STOP_INTERVAL 8                     /* Number of chars per tab stop */
#define LINE_LENGTH (TAB_STOP_INTERVAL * 6)     /* Length of each line before hitting a folding point */
#define TRUE 1
#define FALSE 0

int get_line(char line[], int maxLength);               /* Get user input text */
int fold(int wordLength, int column, int tabOffset);    /* Check to see if a fold to the next line is needed */
int tab_offset(int column, int tabStopInterval);        /* In case of tab chars, return amount of spaces to offset column */

/*
Exercise 1-22: Write a program to "fold" long input lines into two or more shorter lines
after the last non-blank character that occurs before the n-th column of input.
Make sure your program does something intelligent with very long lines,
and if there are no blanks or tabs before the specified column.
*/

int main()
{
	int length;
	char line[MAX_LINE];

	while ((length = get_line(line, MAX_LINE)) > 0) {
		printf("%s\n", line);
	}

	return 0;

}

int get_line(char line[], int maxLength) {
	int c, i, j, column;
	char word[MAX_LINE];

	column = 0;

	for (i = j = 0; (c = getchar()) != EOF && c != '\n'; ) {

		if (i < maxLength - 1) {
			if (c == ' ' || c == '\t') {
				if (fold(j, column, LINE_LENGTH) == TRUE) {
					line[i] = '\n';
					++i;
					column = 0;
				}

				for (int k = 0; k < j && (i < maxLength - 1); ++k) {
					line[i] = word[k];
					++i;
					++column;
				}

				if (i == maxLength - 1) {
					break;
				}

				j = 0;

				int columnOffset;
				if (c == '\t') {
					columnOffset = tab_offset(column, TAB_STOP_INTERVAL);
				} else {
					columnOffset = 1;
				}

				line[i] = c;
				++i;
				column += columnOffset;

			} else {
				if (fold(j, column, LINE_LENGTH) == TRUE) {
                    if (column > 0) {
                        line[i] = '\n';
                        ++i;
                        column = 0;
                    } else {
                        int k;
                        for (k = 0; k < j && i < maxLength - 1; ++k) {
                            line[i] = word[k];
                            ++i;
                        }
                        if (i == maxLength - 1) {
                            break;
                        }
                        line[i] = '\n';
                        ++i;
                        j = column = 0;
                    }
				}
				word[j] = c;
				++j;
			}
		}
	}

	for (int k = 0; k < j && (i < maxLength - 1); ++k) {
		line[i] = word[k];
		++i;
		++column;
	}

	if (i < maxLength - 1) {
	        line[i] = '\0';
	    } else {
	        line[maxLength - 1] = '\0';
	    }

	return i;
}

int fold(int wordLength, int column, int lineLength) {
	if ((column + wordLength) >= lineLength) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int tab_offset(int column, int tabStopInterval) {
	int flag, columnOffset;
	flag = column / tabStopInterval;
	columnOffset = 0;
	while (flag == (column / TAB_STOP_INTERVAL)) {
		++columnOffset;
		++column;
	}
	return columnOffset;
}

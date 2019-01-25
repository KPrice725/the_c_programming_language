#include <stdio.h>

/*
Exercise 3-2: Write a function escape(s, t) that converts characters like newline and tab into visible escape sequences
like \n and \t as it copies the string t to s.  Use a switch.  Write a function for the other direction as well,
converting escape sequences into the real characters.
*/

int escape(char s[], char t[]);
int unescape(char s[], char t[]);

int main(void) {

	char original[] = "a\ab\bcdebcdeff\ffghij k l mmmm\nnnnnn\nnnopqrr\rrrr\'\'\''''\"\"";
	char escaped[1000];
	char unescaped[1000];
	escape(original, escaped);
	unescape(escaped, unescaped);
	printf("Original String: %s\nEscaped String: %s\nUnescaped String: %s\n", original, escaped, unescaped);
	return 0;
}

/* 
escape: copy s to t, convert any escape sequences into the visible characters.  
Return length of escaped string.
*/
int escape(char s[], char t[]) {

	int i, j;

	for (i = j = 0; s[i] != '\0'; i++) {
		switch (s[i]) {
		case '\a':
			t[j] = '\\';
			j++;
			t[j] = 'a';
			break;
		case '\b':
			t[j] = '\\';
			j++;
			t[j] = 'b';
			break;
		case '\f':
			t[j] = '\\';
			j++;
			t[j] = 'f';
			break;
		case '\n':
			t[j] = '\\';
			j++;
			t[j] = 'n';
			break;
		case '\r':
			t[j] = '\\';
			j++;
			t[j] = 'r';
			break;
		case '\t':
			t[j] = '\\';
			j++;
			t[j] = 't';
			break;
		case '\v':
			t[j] = '\\';
			j++;
			t[j] = 'v';
			break;
		case '\\':
			t[j] = '\\';
			j++;
			t[j] = '\\';
			break;
		case '\'':
			t[j] = '\\';
			j++;
			t[j] = '\'';
			break;
		case '\"':
			t[j] = '\\';
			j++;
			t[j] = '\"';
			break;
		default:
			t[j] = s[i];
		}
		j++;
	}
	t[j] = '\0';
	return j;
}

/* 
unescape: copy s to t, convert instances of visibly printed escape characters to their actual escape character.  
Return length of unescaped string.
*/
int unescape(char s[], char t[]) {

	int i, j;

	for(i = j = 0; s[i] != '\0'; i++) {
		switch (s[i]) {
		case '\\':
			i++;
			switch (s[i]) {
			case 'a':
				t[j] = '\a';
				break;
			case 'b':
				t[j] = '\b';
				break;
			case 'f':
				t[j] = '\f';
				break;
			case 'n':
				t[j] = '\n';
				break;
			case 'r':
				t[j] = '\r';
				break;
			case 't':
				t[j] = '\t';
				break;
			case 'v':
				t[j] = '\v';
				break;
			case '\\':
				t[j] = '\\';
				break;
			case '\'':
				t[j] = '\'';
				break;
			case '\"':
				t[j] = '\"';
				break;
			default:
				t[j] = '\\';
				j++;
				t[j] = s[i];
				break;
			}
			break;
		default:
			t[j] = s[i];
			break;
		}
		j++;
	}
	t[j] = '\0';
	return j;
}

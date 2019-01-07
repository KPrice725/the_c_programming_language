#include <stdio.h>

#define MAXLINE 1000
#define TABSTOPINTERVAL 8

/*
Exercise 1-20: Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop.
Assume a fixed set of tab stops, say every n columns.  Should n be a variable or a symbolic parameter?
*/
int getline(char line[], int maxLine);
int detab(char line[], int index);

int main()
{
    int len;
    char line[MAXLINE];

    //checks to see if getline returns any text, and if so, prints it to the screen.
    while ((len = getline(line, MAXLINE)) > 0) {
        printf("%s\n", line);
    }

}

int getline(char s[], int lim) {
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            if (c == '\t') {
                i = detab(s, i);
            } else {
                s[i] = c;
            }
        }
    }
    if (i < lim - 1) {
        s[i] = '\0';
    } else {
        s[lim - 1] = '\0';
    }
    return i;
}
//detab: replaces a '\t' with the necessary number of ' ' character to fill in the line up to the next tab stop
int detab(char s[], int index) {
    int flag;
    flag = index / TABSTOPINTERVAL;
    while (flag == (index / TABSTOPINTERVAL)) {
        s[index] = ' ';
        ++index;
    }
    return index - 1;
}

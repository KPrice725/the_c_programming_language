#include <stdio.h>

#define MAXLINE 1000
#define TABSTOPINTERVAL 8
//detab program to replace tabs in input with the proper number of blanks to space to the next tab stop
int getline(char line[], int maxLine);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        printf("%s\n", line);
    }

}

int getline(char s[], int lim) {
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            if (c == '\t') {
                int flag, tempIndex;
                tempIndex = i;
                flag = tempIndex / TABSTOPINTERVAL;
                while (flag == (tempIndex / TABSTOPINTERVAL)) {
                    s[tempIndex] = ' ';
                    ++tempIndex;
                }
                i = tempIndex - 1;
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

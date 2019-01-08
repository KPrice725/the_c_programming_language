#include <stdio.h>

#define MAXLINE 1000
#define TABSTOPINTERVAL 8

/*
Exercise 1-21: Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing.
Use the same tab stops as for detab.  When either a tab or a single blank would suffice to reach a tab stop, which should be give preference?
*/

int column; //keeps track of the the column number
int c;      //character value

int getlinex(char line[], int maxLine);
int entab(char line[], int index);

int main()
{
    int len;
    char line[MAXLINE];

    //checks to see if getline returns any text, and if so, prints it to the screen.
    while ((len = getlinex(line, MAXLINE)) > 0) {
        printf("%s\n", line);
    }

}

int getlinex(char s[], int lim) {
    int i;
    extern int c;
    extern int column;

    column = 0;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            if (c == ' ') {
                // If there's a space, check to see if the next character is also a space.
                // If so, run the entab function, otherwise, print the space and the next character as usual
                if ((c = getchar()) == ' ') {
                    i = entab(s, i);
                    if (c != EOF && c != '\n') {
                        s[i] = c;
                        ++column;
                    }
                } else if (c != EOF && c != '\n') {
                    s[i] = ' ';
                    ++i;
                    ++column;
                    s[i] = c;
                    ++column;
                } else {
                    s[i] = ' ';
                    ++i;
                    ++column;
                    break;
                }
            } else if (c == '\t') {
                //adjust the column count to move to the next tab stop
                s[i] = c;
                int flag;
                flag = column / TABSTOPINTERVAL;
                while (flag == (column / TABSTOPINTERVAL)) {
                    ++column;
                }
            } else {
                s[i] = c;
                ++column;
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
//entab: replaces a series of ' ' characters with the necessary number of '\t' characters to fill in the same amount of space
int entab(char s[], int index) {
    int flag, spaceCount, spaceRemainder;
    extern int column;
    extern int c;
    spaceCount = 2;
    spaceRemainder = 0;
    flag = column / TABSTOPINTERVAL;
    //get number of spaces in sequence
    while ((c = getchar()) == ' ') {
        ++spaceCount;
    }
    while (spaceCount > 0) {
        --spaceCount;
        ++column;
        ++spaceRemainder;
        //check to see if tab stop has been reached.
        //if so, insert a tab into the char array, advance its index one character,
        //and reset the spaceRemainder and flag variables
        if (flag != (column / TABSTOPINTERVAL)) {
            s[index] = '\t';
            ++index;
            spaceRemainder = 0;
            flag = column / TABSTOPINTERVAL;
        }
    }
    while (spaceRemainder > 0) {
        s[index] = ' ';
        ++index;
        --spaceRemainder;
    }
    return index;
}

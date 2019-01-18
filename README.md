# the_c_programming_language
My attempt at completing the exercises within Kernighan & Ritchie's "The C Programming Language"

Exercise 1-20: Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.  Should n be a variable or a symbolic parameter?

Exercise 1-21: Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.  When either a tab or a single blank would suffice to reach a tab stop, which should be give preference?

Exercise 1-22: Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.

Exercise 1-23: Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments do not nest.

Exercise 1-24: Write a program to check a C program for rudimentary syntax errors, like unbalanced parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments.

Exercise 2-1: Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.

Exercise 2-2: Write a loop equivalent to the for loop above without using && or ||

Exercise 2-3: Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value.  The allowable digits are 0 through 9, a through f, and A through F.

Exercise 2-4: Write an alternate version of squeeze(s1, s2) that deletes each character in s1 that matches any character in the string s2.

Exercise 2-5: Write the function any(s1, s2), which returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.  (The standard library function strpbrk does the same job but returns a pointer to the location.)

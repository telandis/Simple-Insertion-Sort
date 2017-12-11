/******************************************************************************/
/*Ask user to input a string and print it in parentheses.                     */
/*J. Storer, 2015.                                                            */
/*   Compile: gcc -ansi -Wall -o String String.c                              */
/*   Run it: ./String                                                         */
/*******************************************************************************
For somme n>0, a string is an array char s[n],
   that is indexed from 0 to n-1, and capable of storing some
   number m<n of characters in positions s[0] ... s[m-1],
   where characters are stored in positions s[0] ... s[m-2],
   and position s[m-1] contains the special end of string character '\0'.
For example if n>3 and s = "abc", then:
   s[0]='a', s[1]='b', s[2]='c', s[3]='\0'
   (And it doesn't matter what is stored in s[4] ... s[n-1].)
The \0 is essential if s will be passed to functions that expect strings,
   and the programmer is responsible for inserting '\0' at the end
   when building strings.
Another important special character is \n, the end of line character.
For example, if n>4 and "abc" was read from the user input, then:
   s[0]='a', s[1]='b', s[2]='c', s[3]='\n', s[4]='\0'
Although we may use the notation s[0] to refer to the first character,
   we could also refer to it as *s (s is a pointer to its first character).
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*Maximum length of an input line.*/
#define MAXSTRING 1000

/*Function to read a line from a file (which may be stdin).*/
/*Instead of gets, use fgets to avoid a warning message that gets is "unsafe"*/
/*fgets that takes two additional arguments:*/
/*   a maximum string length*/
/*   a file pointer (which can be "stdin" for the standard input).*/
void ReadLine(char *s, FILE *fp) {
if (fgets(s,MAXSTRING,fp) == NULL) s[0]='\0';
}

/*Function to return the length of a string.*/
/*For an illegal string that does not end with \0, MaxString is returned.*/
int stringLength(char *s) {
int i=0;
while ( (i<MAXSTRING) && (s[i]!='\0') ) i++;
if (s[i]!='\0') {printf("ERROR: Missing string end character.\n\n"); exit(1);}
return (i);
}

/*Function to create a new string t that is a copy of s.*/
/*Add 2 to allow parentheses to be added and 1 for the final \0.*/
int i=0;
char* stringCopy(char *s) {
char *t = malloc(stringLength(s)+2+1);
do {t[i]=s[i];} while (s[i++]!='\0');
return(t);
}


/***************************************************************/
/*main                                                         */
/***************************************************************/
int main() {
int ls, i;

/*Declare s to be a string array that can hold up to 100 bytes.*/
char s[MAXSTRING];

/*Declare a string variable (that points to nothing at the moment).*/
char *cs;

printf("\nEnter a string: ");
ReadLine(s,stdin);

cs = stringCopy(s);

ls = stringLength(s);
for (i=ls; i>=0; i--) cs[i]=cs[i-1];          /*shift right*/
cs[0] = '(';                                  /*add '(' at the left*/
cs[ls] = ')';                                 /*overwrite '\n' with ')'*/
cs[ls+1] = '\0';                              /*add \0*/
printf("\nWith () the string is: %s\n\n",cs); /*print cs*/

return 0;
}
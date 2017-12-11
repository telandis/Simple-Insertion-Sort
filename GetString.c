/********************************************************/
/*Input a string and print it.                          */
/*J. Storer, 2015.                                      */
/*   Compile: gcc -ansi -Wall -o GetString GetString.c  */
/*   Run it: ./GetString                                */
/********************************************************/
#include <stdio.h>
int main() {

/*Declare a string array of 100 characters.*/
char x[100];

/*Get string of length <100 from the standard input.*/
printf("\nEnter a string: ");
fgets(x,100,stdin);

/*Print x.*/
printf("\nYou entered: %s\n",x);

return 0;
}
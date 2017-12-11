/***********************************************************/
/*Example of two ways to declare a 2D array.               */
/*J. Storer, 2015.                                         */
/*   Compile: gcc -ansi -Wall -o Array2D Array2D.c         */
/*   Run it: ./Array2D                                     */
/************************************************************
Although both ways are referenced the same, like A[x][y],
the resulting data type and storage used is different.
************************************************************/
#include <stdio.h>
int main() {
int i,j;

/*Initialize rectangular 2D array to some strings:*/
/*Each row is 80 chars long even if it is not all used.*/
char A[3][80] = {"Hello",
                 "Have a nice day.",
                 "Goodbye"};

/*Declare array of pointers (initially point to nothing).*/
char *B[3];

/*Assign a different length string to each row,*/
/*and let the system allocate the correct number of bytes*/
/*to store the row string followed by the ending \0.*/
B[0] = "Hello";
B[1] = "Have a nice day.";
B[2] = "Goodbye";


/***********************************************************/
/*Print rectangular array:*/

printf("\nRectangular array:\n");
for (i=0; i<=2; i++) printf("%s\n",A[i]);

printf("\nRectangular array, one char at a time:\n");
for (i=0; i<=2; i++) {
   for (j=0; A[i][j]!='\0'; j++) printf("%c",A[i][j]);
   printf("\n");
   }


/***********************************************************/
/*Print pointer based array:*/

printf("\nPointer based array:\n");
for (i=0; i<=2; i++) printf("%s\n",B[i]);

printf("\nPointer based array, one char at a time:\n");
for (i=0; i<=2; i++) {
   for (j=0; B[i][j]!='\0'; j++) printf("%c",B[i][j]);
   printf("\n");
   }


/***********************************************************/
/*Print pointer based array with pointer arithmetic:*/

printf("\nPointer arithmetic:\n");
for (i=0; i<=2; i++) printf("%s\n",*(B+i));

printf("\nPointer arithmetic, one char at a time:\n");
for (i=0; i<=2; i++) {
   for (j=0; B[i][j]!='\0'; j++) printf("%c",*(*(B+i)+j));
   printf("\n");
   }


/***********************************************************/
printf("\n");
return 0;
}
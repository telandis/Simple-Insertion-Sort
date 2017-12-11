/**************************************************************/
/*The malloc function for memory allocation.                  */
/*J. Storer, 2015.                                            */
/*   Compile: gcc -ansi -Wall -o Malloc Malloc.c              */
/*   Run it: ./Malloc                                         */
/**************************************************************/
#include <stdio.h>  /*input / output functions*/
#include <stdlib.h> /*system functions malloc, sizeof, etc.*/
int main() {
int *A;
int n, i;

/*Ask user to input a value for n.*/
printf("\nEnter an integer: ");

/*The scanf function takes a pointer to n into which a*/
/*value of type int entered by the user is placed.*/
/*"%d" specifies that a string of type int is expected.*/
/*&n specifies a pointer to the variable n.*/
scanf("%d",&n);

/*Allocate memory for array A to store n values of type int.*/
/*Malloc returns a number of bytes given by its argument.*/
/*sizeof(int) returns how many bytes are needed for type int,*/
/*and then multiply by n to get the number of bytes needed.*/
A = malloc(n*sizeof(int));

/*If the operating system cannot provide the requested*/
/*sequence of bytes in memory, malloc returns NULL;*/
/*always check for this.*/
if (A==NULL) {printf("Malloc failed."); exit(1);}

/*Set A to the first 10 non-negative even integers.*/
for (i=0; i<n; i++) A[i] = 2*i;

/*Print A.*/
printf("\nThe first %d even integers are:",n);
for (i=0; i<10; i++) printf(" %d",A[i]);
printf("\n\n");

/*Give the memory for A back to the operating system.*/
/*A still exists, but no longer points to any valid memory.*/
/*Although the memory used by A is insignificant here,*/
/*freeing no longer used memory can be important when many*/
/*objects are created and only used for a limited time.*/
free(A);

return 0;
}
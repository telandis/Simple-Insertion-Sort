/***********************************************************/
/*Arrays.                                                  */
/*J. Storer, 2015.                                         */
/*   Compile: gcc -ansi -Wall -o Array Array.c             */
/*   Run it: ./Array                                       */
/************************************************************
Arrays are indexed starting at 0.
For example int A[6] stores 6 integers in A[0] to A[5].
The name A is a pointer to the first item of A.
So A[0] and *A both refer to the first item of A,
and A[3] and *A[3] both refer to the fourth item of A.
In addition, pointer arithmetic may be used to reference
items of A. Because the compiler knows the type of A,
adding 1 to a pointer to an item of A points to the next
item of A. For example, *A+3 referes to the fourth item of A.
************************************************************/
#include <stdio.h>

/*This function prints the nth item of an array A,*/
/*where A is required to hold exactly 10 integers,*/
/*that are indexed from 0 to 9.*/
void P1(int n, int A[10]) {printf("A[%d] = %d\n\n",n,A[n]);
}

/*Here are three equivalent functions to print the nth*/
/*item of an array A of integers, where the size of A*/
/*is not specified.*/

   /*Declare as A[].*/
   void P2(int n, int A[]) {printf("A[%d] = %d\n\n",n,A[n]);}

   /*Like P2, by use equivalent declaration *A.*/
   void P3(int n, int *A) {printf("A[%d] = %d\n\n",n,A[n]);}

   /*Like P3, but reference A using pointer arithmetic.*/ 
   void P4(int n, int *A) {printf("A[%d] = %d\n\n",n,*A+n);}


/***********************************************************/
/*main                                                     */
/***********************************************************/
int main() {
printf("\nTest array functions:\n\n");

/*Declare a little array initialized so X[i]=i.*/
int X[10] = {0,1,2,3,4,5,6,7,8,9};

/*These 4 calls all print the fourth item of A, A[3].*/

   P1(3,X);

   P2(3,X);

   P3(3,X);

   P4(3,X);

/*This call causes memory beyond A to be accessed.*/
/*Probably, because this is only a little past A,*/
/*it will still be in the program's memory space,*/
/*and whatever happens to be there will be printed.*/

   P2(11,X);

/*This call will probably cause a system error*/
/*(e.g., a segmentation fault), because it will*/
/*likely access memory outside of program's space.*/

   P2(1000000,X);

return 0;
}
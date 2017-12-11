/********************************************************/
/*Functions (and call by value using pointers).         */
/*J. Storer, 2015.                                      */
/*   Compile: gcc -ansi -Wall -o Function Function.c    */
/*   Run it: ./Function                                 */
/*********************************************************
When invoking a function, C (and other languages in
the C family such as C++ and JAVA) use call by value.
That is a local copy is made of an argument
before it is used and possibly modified by the function.
In order to have a function modify an argument in a
way that the modification will remain after it returns,
a pointer to the value can be passed.
In C (and also C++) &x denotes a pointer to x and *x
denotes what x points to. By passing &x to a function,
the function can modify *x, and after returning,
the changes to x will have been made.
Note that JAVA does not have pointers, but a reference
(e.g. a class variable) captures a basic use of a pointer.
*********************************************************/
#include <stdio.h>

/*This function correctly returns the absolute value.*/
int ABS1(int i) {
if (i<0) i = -i;
return(i);
}

/*This function does nothing.*/
void ABS2(int i) {
if (i<0) i = -i;
}

/*This function changes i to be its absolute value.*/
void ABS3(int *i) {
if (*i<0) *i = - *i;
}


/********************************************************/
/*main                                                  */
/********************************************************/
int main() {
int n;

/*The call to ABS1 correctly returns the absolute value.*/
n = -1;
printf("Using ABS1, answer is: %d\n",ABS1(n));

/*Calling ABS2 does not change the value of n.*/
n = -1;
ABS2(n);
printf("Using ABS2, answer is: %d\n",n);

/*Calling ABS3 with a pointer to n changes the value of n.*/
n = -1;
ABS3(&n);
printf("Using ABS3, answer is: %d\n",n);

return 0;
}
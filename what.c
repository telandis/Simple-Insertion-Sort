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
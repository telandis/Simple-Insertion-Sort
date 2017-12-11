#include <stdio.h> /*input-output functions*/
int main() {
	int i;

	/*Skip line (specified by \n) and print text.*/
	printf("\nEnter an integer: ");

	/*Get an integer typed by the user.*/
	/*In quotes is a template; %d designates an integer.*/
	/*Integer is put in i, which must be preceded by &.*/
	scanf("%d", &i);

	/*Skip line, print text with %d replaced by i,*/
	/*goto next line, and skip line.*/
	printf("\nYou entered: %d\n\n",i);

	return 0;
}
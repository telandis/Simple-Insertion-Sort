/*
Victor Zhu
COSI 21A Jim Storer
PA0
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct vbody {//used portions of code from handouts on cosi site
   struct vbody *next;
   int data;
} TypeVertex;

typedef TypeVertex *TypeList;//used portions of code from handouts on cosi site

TypeVertex *allocateVertex() {//used portions of code from handouts on cosi site
	TypeVertex *p = malloc(sizeof(struct vbody));
	if (p==NULL) {printf("Malloc failed."); exit(1);}
	return p;
}

//takes a int, creates new vertex and inserts it in its location by order in list
void INSERTIONSORT(int num, TypeList *L) {
	TypeVertex *w = allocateVertex();//new vertex
	TypeVertex *v;//current vertex
	TypeVertex *temp = NULL;//previous vertex
	w->data = num;
	v = *L;
	if (v == NULL) {//if the list is empty, just adds vertex into empty list
		w->next = *L;
   		*L = w;
   	} else {
   		//while loop to iterate through list until it reaches end or finds a larger int
   		while(v != NULL && v->data < num) {
		temp = v;
		v = v->next;
		}
		if(temp == NULL) {//only 1 vertex in list and is greater than inserted vertex
			w->next = v;
			*L = w;
		} else if(v == NULL) {//only 1 vertex in list but is less than inserted vertex
			temp->next = w;
			w->next = NULL;
		} else {//otherwise insert between previous and current vertex
			temp->next = w;
			w->next = v;
		}
   	}
}

void printList(TypeList L) {//prints all the integers in the list
	TypeVertex *v;//used portions of code from handouts on cosi site
	for (v=L; v!=NULL; v = v->next) printf("%d\n", v->data);
}

void FREELIST(TypeList *L) {//frees up memory of the list for a new input
	TypeVertex *v;
	TypeVertex *temp = NULL;
	for (v=*L; v!=NULL; v = v->next) {
		if(temp != NULL) {
			free(temp);
		}
		temp = v;
	}
	free(temp);
}

//main method that prompts user for int inputs and returns sorted list of integers
int main() {
	printf("Hello.\n");
	int boolean = 1;//pseudo boolean to break out of loop

	while(boolean == 1) {
		//initialize variables
		TypeVertex *L = NULL;
		int num;
		char iniInput[10];
		char again = 'g';
		printf("\nINPUT LIST (one integer per line followed by an empty line):\n");
		while (fgets(iniInput, sizeof iniInput, stdin) != NULL) {
			//takes input and checks if it is integer, otherwise breaks out of loop
  			if (sscanf(iniInput, "%d", &num) != 1) break;
  			// do stuff with data
  			INSERTIONSORT(num, &L);
		}
		printf("SORTED LIST:\n");
		//print sorted list
		printList(L);
		if(L == NULL) {//if list is empty prints out statement
			printf("List is empty.\n");
		}
		while(again != 'y' && again != 'n') {//prompts user if they want to continue
			printf("\nDo it again (y/n)? ");
			//accept y or n
			fgets(&again,10,stdin);
		}
		if(again == 'n') {//ends loop
			boolean = 0;
		}
		//printf("\n");
		FREELIST(&L);//frees up memory in list L
	}

	printf("\nGoodbye.\n");
	return 0;
}
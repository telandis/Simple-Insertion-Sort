/***************************************************************/
/*Linked lists.                                                */
/*J. Storer, 2015.                                             */
/*   Compile: gcc -ansi -Wall -o List List.c                   */
/*   Run it: ./List                                            */
/****************************************************************
For this example, a linked list vertex has just two fields:
   next - pointer to next vertex in the list (NIL if last vertex)
   data - a single character
It is singly linked, but we could have had an additional
   prev field that store a pointer to the preceding vertex.
There is no list header, a list is a pointer to its first vertex.
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MaxString 100

/*Define a vertex to be a structure with two fields.*/
typedef struct vbody {
   struct vbody *next;
   char data;
   } TypeVertex;

/*Define a singly-linked list to be a pointer to a vertex.*/
typedef TypeVertex *TypeList;

/*Function to allocate memory for a new vertex.*/
TypeVertex *allocateVertex() {
TypeVertex *p = malloc(sizeof(struct vbody));
if (p==NULL) {printf("Malloc failed."); exit(1);}
return p;
}

/*FIRST VERSION OF AN INSERT FUNCTION*/
/*This version always inserts into the same list.*/
/*Define a global variable X to be of type list.*/
/*Insert into X after vertex v a new vertex with data c.*/
/*The argument v=NULL means insert at the beginning of X.*/
TypeList X=NULL;
void INSERT1(char c, TypeVertex *v) {
TypeVertex *w = allocateVertex();
w->data = c;
if (v==NULL) {
   w->next = X;
   X = w;
   }
else {
   w->next = v->next;
   v->next = w;
   }
}

/*SECOND VERSION OF AN INSERT FUNCTION*/
/*Insert into list L after vertex v a new vertex with data c.*/
/*v=NULL means insert at the beginning of the list.*/
/*More general than INSERT1 becasue any list could be passed to it.*/ 
/*However, a bit "ugly" to have to call it with an assignment statement.*/
TypeList INSERT2(char c, TypeVertex *v, TypeList L) {
TypeVertex *w = allocateVertex();
w->data = c;
if (v==NULL) {
   w->next = L;
   L = w;
   }
else {
   w->next = v->next;
   v->next = w;
   }
return L;
}

/*OUR FINAL VERSION OF AN INSERT FUNCTION*/
/*This function modifies L and returns nothing.*/
/*Insert into list L after vertex v a new vertex with data c.*/
/*v=NULL means insert at the beginning of the list.*/
/*Because may have to modify L, it is passed a pointer to L*/
/*(i.e., *L is a pointer to a pointer).*/
/*NOTE:
   Although arguments in C are passed by value (and so modifying
   arguments has no effect on those arguments when the function returns),
   the change to what an argument points to remains after we return.
   */
void INSERT(char c, TypeVertex *v, TypeList *L) {
TypeVertex *w = allocateVertex();
w->data = c;
if (v==NULL) {
   w->next = *L;
   *L = w;
   }
else {
   w->next = v->next;
   v->next = w;
   }
}

/*Function to print the items of a list, one per line.*/
void printList(TypeList L) {
int i=0;
TypeVertex *v;
for (v=L; v!=NULL; v = v->next) printf("Vertex %d = \'%c\'\n",++i,v->data);
}

/*Function make a copy of a list in reverse order and return it.*/
/*The C syntax &M specifies a pointer to M.*/
/*By passing &M, the INSERT function will modify M, not a copy of M.*/
TypeList reverseCopy(TypeList L) {
TypeList M = NULL;
TypeVertex *v;
for (v=L; v!=NULL; v = v->next) INSERT(v->data,NULL,&M);
return M;
}


/***************************************************************/
/*main                                                         */
/***************************************************************/
int main() {
TypeVertex *v;

/*Let's start by adding a vertex to X "manually", with data 'D".*/
X = allocateVertex();
(*X).next = NULL;
(*X).data = 'D';

/*Now "manually" place another vertex at the start of X, with data item F.*/
/*Except this time, use the -> notation; for example,*/
/*X->next is a shortcut for (*X).next, which looks nicer in practice.*/  
v = allocateVertex();
X->next = v;
v->next = NULL;
v->data = 'F';

/*Let's now put C at the front of X using the INSERT1 function.*/
INSERT1('C',NULL);

/*Let's now put B at the front of X using the INSERT2 function.*/
X = INSERT2('B',NULL,X);

/*Let's now put A at the front of X using the INSERT function.*/
INSERT('A',NULL,&X);

/*Now find vertex D and put E after it.*/
v = X;
while ( (v!=NULL) && ((v->data)!='D') ) v = v->next;
INSERT('E',v,&X);

/*Now walk through list X and print each vertex - A,B,C,D,E,F.*/
printf("\nThe list X:\n");
printList(X);

/*Now make a copy of X in reverse order and print it - F,E,D,C,B,A.*/
printf("\nThe list X reversed:\n");
printList(reverseCopy(X));
printf("\n");

return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

typedef struct Node * nodePtr;

struct Node{
    int data;
    nodePtr next;
};


nodePtr L;

void insertionSort(nodePtr curr){
    nodePtr s_list = curr;
    nodePtr insrtPtr = s_list;
    curr = curr->next;
    while(curr != NULL){
        insrtPtr = s_list;
        while(insrtPtr->next != NULL){
            if (insrtPtr->data > curr->data){
                int temp = curr->data;
                curr->data = insrtPtr->data;
                insrtPtr->data = temp;
            }else{
                insrtPtr = insrtPtr->next;
            }
        }
        curr = curr->next;
    }
}

void add(nodePtr *s_list, int data){
    nodePtr newNode = (nodePtr) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if ((*s_list) == NULL){
        *s_list = newNode;
        L = *s_list;
    }else{
        (*s_list)->next = newNode;
        *s_list = newNode;
    }
}

void clearList(nodePtr *s_list){
    if(*s_list != NULL){
        clearList(&(*s_list)->next);
    }
    free(*s_list);
    *s_list = NULL;
}

void printList(nodePtr s_list){
    nodePtr curr = s_list;
    while(curr != NULL){
    	printf("%d \n",curr->data);
    	curr = curr->next;
    }
    printf("\n");
}

int main(void){
    printf("Hello. \n");
    char resp = 'n';
    do{
	nodePtr s_list = NULL;
        char string[100];
        int number;
        printf("\nINPUT LIST (one integer per line followed by an empty line): \n");
        while(TRUE){
            fgets(string, 100, stdin);
            if(string[0] == '\n') break;
            number = atoi(string);
            add(&s_list, number);
        }
        insertionSort(L);
        printf("SORTED LIST: \n");    
	printList(L);
        clearList(&s_list);  
	printf("Do it again (y/n)? \n\n");
	resp = getchar();
    }while(resp == 'y');
    
    printf("\nGoodbye.");
    
    return 0;
}
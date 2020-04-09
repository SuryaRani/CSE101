//-----------------------------------------------------------------------------
// Matrix.c
// Surya Rani 
// srani
// pa2
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include "List.h"

int main(){
	List L = newList();
	//File *out;
	printf("Length %d\n", length(L));
	append(L,2);
	printf("Front: %d\n",front(L));
	prepend(L,1);
	printf("back: %d\n",back(L));
	printf("Front: %d\n",front(L));
	printf("Length %d\n", length(L));
	printList(stdout, L);
	printList(stdout,copyList(L));
	moveFront(L);
	insertBefore(L,4);
	printf("Front: %d\n",front(L));
	deleteFront(L);
	printf("Front: %d\n",front(L));
	deleteFront(L);
	printf("Front: %d\n",front(L));
	clear(L);
	freeList(&L);
	L=NULL;


}
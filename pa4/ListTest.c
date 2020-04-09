//-----------------------------------------------------------------------------
// Surya Rani, srani, Pa4
// ListTest.c
// Test file for List ADT
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main()
{
	List L = newList();
	append(L, 4);
	append(L, 5);
	append(L, 6);
	append(L, 3);
	append(L, 9);
	append(L, 1);

	printList(stdout, L);
	printf("\n");

	moveFront(L);
	moveNext(L);
	set(L, 34);
	printList(stdout, L);
	printf("\n");

	moveNext(L);
	set(L, 40);
	printList(stdout, L);
	printf("\n");

	moveFront(L);
	set(L, 88);
	printList(stdout, L);
	printf("\n");

	moveBack(L);
	printf("INDEX: %d\n", index(L));
	printf("Length: %d\n", length(L));

	set(L, 29);
	printList(stdout, L);
	printf("\n");

	/*printf("Length %d\n", length(L));
	append(L, 2);
	printf("Length %d\n", length(L));
	printList(stdout, L);
	append(L, 4);
	append(L, 6);
	printf("Length %d\n", length(L));
	printf("Front: %d\n", front(L));
	printList(stdout, L);

	prepend(L, 1);
	printf("Front: %d\n", front(L));
	printf("Length %d\n", length(L));
	printList(stdout, L);

	prepend(L, 4);
	printf("Front: %d\n", front(L));
	printf("Length %d\n", length(L));
	prepend(L, 3);
	printList(stdout, L);

	printf("Front: %d\n", front(L));
	printf("Length %d\n", length(L));
	printf("back: %d\n", back(L));
	printf("Index: %d\n", index(L));
	moveFront(L);
	printf("Index: %d\n", index(L));
	printf("Front: %d\n", front(L));
	printList(stdout, L);

	deleteFront(L);
	printf("Index: %d\n", index(L));
	printf("Front: %d\n", front(L));
	printf("Length %d\n", length(L));
	printList(stdout, L);

	moveBack(L);
	printf("Index: %d\n", index(L));
	printf("back: %d\n", back(L));
	printf("Get: %d\n", get(L));
	printList(stdout, L);

	deleteBack(L);
	printf("back: %d\n", back(L));

	printf("Index: %d\n", index(L));
	printf("Length %d\n", length(L));
	printList(stdout, L);

	moveBack(L);
	movePrev(L);
	printf("GEt: %d\n", get(L));

	delete (L);
	printList(stdout, L);

	printf("Length %d\n", length(L));
	printf("Index: %d\n", index(L));
	moveFront(L);
	moveNext(L);
	printf("GEt: %d\n", get(L));
	printf("Started before\n");

	insertBefore(L, 9);
	printList(stdout, L);
	printf("Index: %d\n", index(L));
	printf("GEt: %d\n", get(L));
	printf("Started insert\n");

	insertAfter(L, 8);
	printList(stdout, L);
	printf("Inserted AFter\n");
	insertBefore(L, 303);
	printf("Iniserted before\n");
	printList(stdout, L);
	printf("\n");

	deleteFront(L);
	printList(stdout, L);
	printf("\n");

	printf("Index: %d\n", index(L));
	printf("GEt: %d\n", get(L));
	set(L, 4);
	printList(stdout, L);
	printf("\n");

	printf("I COPIED LIST");
	List N = copyList(L);

	printf("STarting the equals\n");
	printf("%d", equals(L, N));
	printf("\n");

	deleteBack(N);
	printf("Wont be equal \n");
	printf("%d", equals(L, N));
	printf("\n");

	deleteBack(L);
	printf("WIell be equal \n");
	printf("%d", equals(L, N));
	printf("\n");
	printList(stdout, N);

	clear(N);
	freeList(&N);

	clear(L);

	append(L, 3);
	printList(stdout, L);
	moveFront(L);
	printf("IM SETTING HERE\n");
	set(L, 4);
	moveNext(L);
	printList(stdout, L);
	set(L, 55);

	deleteFront(L);
	printf("DE:ET");
	printList(stdout, L);

	clear(L);
	freeList(&L);
	L = NULL;
	*/
	/*
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
	*/

	clear(L);
	freeList(&L);
	L = NULL;
}
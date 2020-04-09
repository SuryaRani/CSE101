//-----------------------------------------------------------------------------
// Surya Rani, srani, Pa4
// GraphTest.c
// Implementation file for to test Graph ADT
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Graph.h"

int main()
{
    Graph G = newGraph(6);
    printf("ORDER: %d\n", getOrder(G));
    printf("SIZE: %d\n", getSize(G));
    printf("SOURCE: %d\n", getSource(G));
    printf("PARENT: %d\n", getParent(G, 2));
    printf("DISTANCE: %d\n", getDist(G, 3));

    addEdge(G, 1, 2);

    addEdge(G, 1, 3);

    addEdge(G, 2, 4);
    addEdge(G, 2, 5);
    addEdge(G, 2, 6);
    printf("THIS IS where 4 goes:\n");

    addEdge(G, 3, 4);
    printf("THIS IS where 5 goes:\n");

    addEdge(G, 4, 5);
    addEdge(G, 5, 6);

    printf("ORDER: %d\n", getOrder(G));
    printf("SIZE: %d\n", getSize(G));
    printf("SOURCE: %d\n", getSource(G));
    printf("PARENT: %d\n", getParent(G, 2));
    printf("DISTANCE: %d\n", getDist(G, 3));

    BFS(G, 1);

    printf("The Distance from 1 to 5 is: %d\n", getDist(G, 5));
    printf("THE PATH FROM 1 to 5 is ");
    List L = newList();
    getPath(L, G, 5);
    printList(stdout, L);
    printf("\n");

    clear(L);
    freeList(&L);
    L = NULL;

    printGraph(stdout, G);
    makeNull(G);
    freeGraph(&G);
}
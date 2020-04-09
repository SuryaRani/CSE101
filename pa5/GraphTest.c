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
    Graph G = newGraph(8);
    addArc(G, 1, 2);
    addArc(G, 2, 3);
    addArc(G, 2, 5);
    addArc(G, 2, 6);
    addArc(G, 3, 4);
    addArc(G, 3, 7);
    addArc(G, 4, 3);
    addArc(G, 4, 8);
    addArc(G, 5, 1);
    addArc(G, 5, 6);
    addArc(G, 6, 7);
    addArc(G, 7, 6);
    addArc(G, 8, 8);

    printGraph(stdout, G);
    Graph transp = transpose(G);
    printGraph(stdout, transp);

    List stack = newList();
    for (int i = 1; i <= 8; i++)
    {
        append(stack, i);
    }
    printf("THIS IS STACK BEFORE\n");
    printList(stdout, stack);

    printf("DFS ON NORMAL GRAPH\n");
    DFS(G, stack);
    printf("\n");
    printList(stdout, stack);

    printf("THIS IS TRANSPOSE DFS\n");
    DFS(transp, stack);
    printf("\n");
    printList(stdout, stack);
    printf("\n");

    moveBack(stack);
    for(int i = 1; i<=length(stack);i++){
        printf("THIS IS GET %d\n",get(stack));
        printf("THIS IS PARENT %d\n",getParent(transp,get(stack)));
        movePrev(stack);
    }

}
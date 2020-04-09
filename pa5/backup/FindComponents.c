//-----------------------------------------------------------------------------
// Surya Rani, srani, Pa4
// FindPath.c
// Implementation file for client module FindPath
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Graph.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    int vertices;
    int edge1 = -1;
    int edge2 = -1;

    fscanf(in, "%d", &vertices);
    Graph G = newGraph(vertices);

    while (edge1 != 0 && edge2 != 0)
    {
        fscanf(in, "%d %d", &edge1, &edge2);
        if (edge1 != 0 && edge2 != 0)
        {
            addArc(G, edge1, edge2);
        }
    }
    fprintf(out, "Adjacency list representation of G:\n");
    printGraph(out, G);
    fprintf(out, "\n");

    List stack = newList();
    for (int i = 1; i <= vertices; i++)
    {
        append(stack, i);
    }

    /*printf("THIS IS LIST\n");
    printList(stdout, stack);
    printf("\n");
    printf("This is order: %d\n", getOrder(G));
    */

    DFS(G, stack);

    Graph transp = transpose(G);
    /*printf("THIS IS LIST\n");
    printList(stdout, stack);
    printf("\n");
    printf("This is order: %d\n", getOrder(G));
    */
    DFS(transp, stack);

    int parent;
    moveBack(stack);
    //printf("THiS IS STACK\n");
    //printList(stdout, stack);
    int conn = 0;
    for (int i = 1; i <= length(stack); i++)
    {

        parent = getParent(transp, get(stack));
        //printf("Get: %d\n", get(stack));
        //printf("Parent: %d\n", parent);
        if (parent == NIL)
        {
            conn++;
        }
        movePrev(stack);
    }

    fprintf(out, "G contains %d strongly connected components:\n", conn);
    moveBack(stack);
    int count = 1;
    parent = NIL;
    List printer = newList();
    for (int i = 1; i <= conn; i++)
    {
        if (index(stack) != -1)
        {
            parent = getParent(transp, get(stack));
        }
        fprintf(out, "Component %d: ", count);
        while (parent != NIL)
        {
            //printf("THIS IS THE LOOP\n");
            if (index(stack) != -1)
            {
                prepend(printer, get(stack));
                //fprintf(out, " %d", get(stack));
            }
            movePrev(stack);
            if (index(stack) != -1)
            {
                parent = getParent(transp, get(stack));
            }
            else
            {
                parent = NIL;
            }
        }
        if (parent == NIL)
        {
            //printf("TRUE\n");
            if (index(stack) != -1)
            {
                prepend(printer, get(stack));
                //fprintf(out, " %d", get(stack));
            }
            movePrev(stack);
        }
        printList(out, printer);
        clear(printer);
        fprintf(out, "\n");
        count++;
    }

    /*for (int i = 1; i <= length(stack); i++)
    {

        parent = getParent(transp, get(stack));
        fprintf(out, "Component %d:", count);
        if (parent == NIL)
        {
            fprintf(out, " %d", get(stack));

            movePrev(stack);
            if (index(stack) != -1)
            {
                while (parent != NIL)
                {
                    fprintf(out, " %d", get(stack));
                    movePrev(stack);
                    if (index(stack) != -1)
                    {
                        parent = getParent(transp, get(stack));
                    }
                    else
                    {
                        break;
                    }
                }
                fprintf(out, "\n");
                count++;
            }
        }
    }*/

    clear(stack);
    stack = NULL;
    fclose(in);
    fclose(out);
}
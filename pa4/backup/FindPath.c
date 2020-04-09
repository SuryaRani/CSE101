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
    int src = -1;
    int dst = -1;
    fscanf(in, "%d", &vertices);
    Graph G = newGraph(vertices);
    while (edge1 != 0 && edge2 != 0)
    {
        fscanf(in, "%d %d", &edge1, &edge2);
        if (edge1 != 0 && edge2 != 0)
        {
            addEdge(G, edge1, edge2);
        }
    }
    printGraph(out, G);
    fprintf(out, "\n");

    while (src != 0 && dst != 0)
    {
        fscanf(in, "%d %d", &src, &dst);
        if (src != 0 && dst != 0)
        {
            List L = newList();
            BFS(G, src);
            getPath(L, G, dst);
            if (getDist(G, dst) == INF)
            {
                fprintf(out, "The distance from %d to %d is infinity\n", src, dst);
            }
            else
            {
                fprintf(out, "The distance from %d to %d is %d\n", src, dst, getDist(G, dst));
            }
            if (getDist(G, dst) == INF)
            {
                fprintf(out, "No %d-%d path exists", src, dst);
            }
            else
            {
                fprintf(out, "A shortest %d-%d path is: ", src, dst);
                printList(out, L);
            }

            fprintf(out, "\n");
            fprintf(out, "\n");
            clear(L);
            freeList(&L);
        }
    }

    makeNull(G);
    freeGraph(&G);

    fclose(in);
    fclose(out);
}
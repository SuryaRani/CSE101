//-----------------------------------------------------------------------------
// Surya Rani, srani, Pa5
// Graph.c
// Implementation file for Graph ADT
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Graph.h"

typedef struct GraphObj
{
    List *adj;
    int *color;
    int *p;
    int *d;
    int *f;
    int order;
    int size;
    int source;
} GraphObj;

typedef GraphObj *Graph;

/*** Constructors-Destructors ***/
Graph newGraph(int n)
{
    Graph G;
    G = malloc(sizeof(GraphObj));
    G->adj = (List *)malloc(sizeof(List) * (n + 1));
    for (int i = 1; i <= n; i++)
    {
        G->adj[i] = newList();
    }
    G->color = malloc(sizeof(int) * (n + 1));
    G->p = malloc(sizeof(int) * (n + 1));
    G->d = malloc(sizeof(int) * (n + 1));
    G->f = malloc(sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++)
    {
        G->d[i] = UNDEF;
        G->f[i] = UNDEF;
    }
    G->order = n;
    G->size = 0;
    G->source = NIL;
    return G;
}
void freeGraph(Graph *pG)
{
    if (pG != NULL && *pG != NULL)
    {
        free(*pG);
        *pG = NULL;
    }
}
/*** Access functions ***/
int getOrder(Graph G)
{
    return G->order;
}
int getSize(Graph G)
{
    return G->size;
}
int getParent(Graph G, int u)
{
    if (u < 1)
    {
        printf("Graph Error: calling getParent() with input being less than 1\n");
        exit(1);
    }

    if (u > getOrder(G))
    {
        printf("Graph Error: calling getDist() with input being greater than graph order\n");
        exit(1);
    }
    return G->p[u];
}

int getDiscover(Graph G, int u)
{ /* Pre: 1<=u<=n=getOrder(G) */
    if (u > getOrder(G))
    {
        printf("Graph Error: calling getDiscover() with input being greater than graph order\n");
        exit(1);
    }
    if (u < 1)
    {
        printf("Graph Error: calling getDiscover() with input being less than 1\n");
        exit(1);
    }
    return G->d[u];
}
int getFinish(Graph G, int u)
{ /* Pre: 1<=u<=n=getOrder(G) */
    if (u > getOrder(G))
    {
        printf("Graph Error: calling getFinish() with input being greater than graph order\n");
        exit(1);
    }
    if (u < 1)
    {
        printf("Graph Error: calling getFinish() with input being less than 1\n");
        exit(1);
    }
    return G->f[u];
}
/*** Manipulation procedures ***/
void addEdge(Graph G, int u, int v)
{
    if (u < 1 || v < 1)
    {
        printf("Graph Error: calling addEdge() one or both inputs are less than 1\n");
        exit(1);
    }

    if (u > getOrder(G) || v > getOrder(G))
    {
        printf("Graph Error: calling addEdge() with one or both inputs being greater than graph order\n");
        exit(1);
    }
    //printf("HERE 0\n");

    if (length(G->adj[v]) == 0)
    {
        append(G->adj[v], u);
        G->size++;
        //printf("HERE 1\n");
    }
    else
    {
        moveFront(G->adj[v]);
        // printf("HERE 2\n");

        for (int i = 1; i <= length(G->adj[v]); i++)
        {
            if (get(G->adj[v]) > u)
            {
                insertBefore(G->adj[v], u);
                G->size++;
                //printf("HERE 4\n");

                break;
            }
            else
            {
                moveNext(G->adj[v]);
                if (index(G->adj[v]) == -1)
                {
                    append(G->adj[v], u);
                    //printf("HERE 7\n");

                    G->size++;

                    break;
                }
                //printf("HERE 5\n");
            }
        }
    }

    if (length(G->adj[u]) == 0)
    {
        append(G->adj[u], v);
        //printf("HERE 6\n");

        //G->size++;
    }
    else
    {
        moveFront(G->adj[u]);
        for (int i = 1; i <= length(G->adj[u]); i++)
        {
            if (get(G->adj[u]) > v)
            {
                insertBefore(G->adj[u], v);
                //printf("HERE 8\n");

                //G->size++;

                break;
            }
            else
            {
                moveNext(G->adj[u]);
                if (index(G->adj[u]) == -1)
                {
                    append(G->adj[u], v);
                    //printf("HERE 7\n");

                    //G->size++;

                    break;
                }
                //printf("HERE 9\n");
            }
        }
    }
    //printf("DONE WIT EDGE\n");
}
void addArc(Graph G, int u, int v)
{
    if (u < 1 || v < 1)
    {
        printf("Graph Error: calling addArc() one or both inputs are less than 1\n");
        exit(1);
    }

    if (u > getOrder(G) || v > getOrder(G))
    {
        printf("Graph Error: calling addArc() with one or both inputs being greater than graph order\n");
        exit(1);
    }

    if (length(G->adj[u]) == 0)
    {
        append(G->adj[u], v);
        //printf("HERE 6\n");

        G->size++;
    }
    else
    {
        moveFront(G->adj[u]);
        for (int i = 1; i <= length(G->adj[u]); i++)
        {
            if (get(G->adj[u]) > v)
            {
                insertBefore(G->adj[u], v);
                //printf("HERE 8\n");

                G->size++;

                break;
            }
            else
            {
                moveNext(G->adj[u]);
                if (index(G->adj[u]) == -1)
                {
                    append(G->adj[u], v);
                    //printf("HERE 7\n");

                    G->size++;

                    break;
                }
                //printf("HERE 9\n");
            }
        }
    }
}
int Visit(Graph G, int x, int time, List S)
{
    G->d[x] = (++time);
    G->color[x] = 1;
    //printf("HERE 9\n");
    if (length(G->adj[x]) > 0)
    {
        moveFront(G->adj[x]);
    }
    //printf("HERE 10\n");

    int y = 0;
    for (int i = 1; i <= length(G->adj[x]); i++)
    {
        //might not account for empty lists idk
        if (index(G->adj[x]) != -1)
        {
            y = get(G->adj[x]);
        }
        if (G->color[y] == 0)
        {
            G->p[y] = x;
            time = Visit(G, y, time, S);
        }
        moveNext(G->adj[x]);
    }
    G->color[x] = 2;
    //printf("THIS IS THE NUMBER BEING PREPENDED:%d\n", x);
    prepend(S, x);
    //printf("LIST\n");
    //printList(stdout, S);
    G->f[x] = (++time);
    return time;
}

void DFS(Graph G, List S)
{
    if (length(S) != getOrder(G))
    {
        printf("Graph Error: calling DFS() the List size does not equal the order of the graph\n");
        exit(1);
    }
    // USE THE FILO STACK AND USE THE PSEUDOCODE POP OFF STACK IN THE SECOND LOOP
    // USE THE POPPED ELEMENT IN VISIT AND KEEP GOING UNTIL AFTER VISIT THEN PUT FINISH TIMES IN THE STACK
    int len = length(S);
    int time;
    //printf("HERE 1\n");
    moveFront(S);
    //printf("HERE 2\n");

    for (int i = 1; i <= len; i++)
    {
        int x;
        if (index(S) != -1)
        {
            x = get(S);
        }
        G->color[x] = 0;
        G->p[x] = NIL;
        moveNext(S);
    }
    time = 0;
    //printf("HERE 3\n");

    moveFront(S);
    //rintf("HERE 4\n");

    for (int i = 1; i <= len; i++)
    {
        int x;
        if (index(S) != -1)
        {
            x = get(S);
            moveNext(S);
        }

        //printf("THIS IS NUMBER BEING USED IN STACK: %d\n", x);
        if (G->color[x] == 0)
        {
            time = Visit(G, x, time, S);
        }
    }
    for (int i = 1; i <= len; i++)
    {
        deleteBack(S);
    }
    // i should be appending in visit everytime it finishes i think

    //printing out the strongly conne
}

/*** Other operations ***/
Graph transpose(Graph G)
{
    Graph trans = newGraph(getOrder(G));
    for (int i = 1; i <= getOrder(G); i++)
    {
        //printf("HERE 6\n");

        if (length(G->adj[i]) > 0)
        {
            moveFront(G->adj[i]);
        }
        //printf("HERE 7\n");

        int swap;
        for (int j = 1; j <= length(G->adj[i]); j++)
        {

            if (index(G->adj[i]) != -1)
            {
                swap = get(G->adj[i]);
            }
            addArc(trans, swap, i);
            moveNext(G->adj[i]);
        }
    }
    return trans;
}
Graph copyGraph(Graph G)
{
    Graph cop = newGraph(getOrder(G));
    for (int i = 1; i <= getOrder(G); i++)
    {
        cop->adj[i] = copyList(G->adj[i]);
    }
    return cop;
}
void printGraph(FILE *out, Graph G)
{
    for (int i = 1; i <= getOrder(G); i++)
    {
        fprintf(out, "%d: ", i);
        printList(out, G->adj[i]);
        fprintf(out, "\n");
    }
}
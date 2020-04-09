//-----------------------------------------------------------------------------
// Surya Rani, srani, Pa4
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
    for (int i = 0; i <= n; i++)
    {
        G->adj[i] = newList();
    }
    G->color = malloc(sizeof(int) * (n + 1));
    G->p = malloc(sizeof(int) * (n + 1));
    G->d = malloc(sizeof(int) * (n + 1));
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
int getSource(Graph G)
{
    return G->source;
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

    if (G->source == NIL)
    {
        return NIL;
    }
    return G->p[u];
}
int getDist(Graph G, int u)
{
    if (u < 1)
    {
        printf("Graph Error: calling getDist() with input being less than 1\n");
        exit(1);
    }

    if (u > getOrder(G))
    {
        printf("Graph Error: calling getDist() with input being greater than graph order\n");
        exit(1);
    }
    if (G->source == NIL)
    {
        return INF;
    }
    return G->d[u];
}

void getPath(List L, Graph G, int u)
{
    if (u < 1)
    {
        printf("Graph Error: calling getPath() with input being less than 1\n");
        exit(1);
    }

    if (u > getOrder(G))
    {
        printf("Graph Error: calling getPath() with input being greater than graph order\n");
        exit(1);
    }
    if (G->source == NIL)
    {
        printf("Graph Error: calling getPath() before calling BFS\n");
        exit(1);
    }

    if (u == G->source)
    {
        append(L, u);
    }
    else if (G->p[u] == NIL)
    {
        printf("%d is not reachable from %d\n", u, G->source);
        append(L, NIL);
        return;
    }
    else
    {
        getPath(L, G, G->p[u]);
        append(L, u);
    }
}
/*** Manipulation procedures ***/
void makeNull(Graph G)
{
    for (int i = 0; i <= G->order; i++)
    {
        clear(G->adj[i]);
        freeList(&G->adj[i]);
        G->adj[i] = NULL;
    }
    G->size = 0;
}
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
void BFS(Graph G, int s)
{
    if (s < 1)
    {
        printf("Graph Error: calling BFS() with input being less than 1\n");
        exit(1);
    }

    if (s > getOrder(G))
    {
        printf("Graph Error: calling BFS() with input being greater than graph order\n");
        exit(1);
    }
    G->source = s;
    for (int x = 1; x < s; x++)
    {
        G->color[x] = 0;
        G->d[x] = INF;
        G->p[x] = NIL;
    }
    for (int x = s + 1; x <= getOrder(G); x++)
    {
        G->color[x] = 0;
        G->d[x] = INF;
        G->p[x] = NIL;
    }
    //printf("GOT OUT OF 1\n");
    G->color[s] = 1;
    G->d[s] = 0;
    G->p[s] = NIL;
    List Q = newList();
    int x = 0;
    append(Q, s);
    while (length(Q) != 0)
    {
        moveFront(Q);
        x = get(Q);
        //printf("THIS IS Each adj matrix %d\n", x);
        deleteFront(Q);
        int y = 0;
        if (length(G->adj[x]) != 0)
        {
            moveFront(G->adj[x]);
        }
        while (index(G->adj[x]) != -1)
        {
            y = get(G->adj[x]);
            if (G->color[y] == 0)
            {
                G->color[y] = 1;
                G->d[y] = G->d[x] + 1;
                G->p[y] = x;
                append(Q, y);
            }

            moveNext(G->adj[x]);
        }

        //printf("GOT OUT OF 2\n");
        G->color[x] = 2;
    }
    clear(Q);
    freeList(&Q);
    Q = NULL;
}
/*** Other operations ***/
void printGraph(FILE *out, Graph G)
{
    for (int i = 1; i <= getOrder(G); i++)
    {
        fprintf(out, "%d: ", i);
        printList(out, G->adj[i]);
        fprintf(out, "\n");
    }
}
//-----------------------------------------------------------------------------
// Surya Rani, srani, Pa5
// Graph.h
// Header file for Graph ADT
//-----------------------------------------------------------------------------

#ifndef _GRAPH_H_INCLUDE_
#define _GRAPH_H_INCLUDE_
#define UNDEF -1
#define NIL 0
typedef struct GraphObj *Graph;
typedef struct ListObj *List;
/*** Constructors-Destructors ***/
Graph newGraph(int n);
void freeGraph(Graph *pG);
/*** Access functions ***/
int getOrder(Graph G);
int getSize(Graph G);
int getParent(Graph G, int u);
int getDiscover(Graph G, int u);
int getFinish(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
/*** Manipulation procedures ***/
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void DFS(Graph G, List S);
/*** Other operations ***/
Graph transpose(Graph G);
Graph copyGraph(Graph G);
void printGraph(FILE *out, Graph G);

#endif
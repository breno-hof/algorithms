#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

#define MAX_NODES 100

// Estrutura para o Grafo
typedef struct {
    int numVertices;
    int adjMatrix[MAX_NODES][MAX_NODES];
} Graph;

// Funções para o Grafo
void initGraph(Graph *graph, int vertices);
void addEdge(Graph *graph, int src, int dest);
void addWeightedEdge(Graph *graph, int src, int dest, int cost);

#endif
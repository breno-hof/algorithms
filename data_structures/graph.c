#include "graph.h"
#include "limits.h"

#define INF INT_MAX

// Inicializa o grafo
void initGraph(Graph *graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = (i == j) ? 0 : INF;
        }
    }
}

// Adiciona uma aresta ao grafo
void addEdge(Graph *graph, int src, int dest) {
    addWeightedEdge(graph, src, dest, 1);
}

// Adiciona uma aresta ao grafo ponderado
void addWeightedEdge(Graph *graph, int src, int dest, int cost) {
    graph->adjMatrix[src][dest] = cost;
    graph->adjMatrix[dest][src] = cost; // Grafo não direcionado
}
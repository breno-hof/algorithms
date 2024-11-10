#include <stdio.h>
#include "./data_structures/graph.h"

// Função DFS recursiva
void DFS(Graph *graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    // Visita os vizinhos do vértice atual
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

int main() {
    Graph graph;
    int numVertices = 5;

    initGraph(&graph, numVertices);

    // Adicionando arestas
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);

    // Array para marcar os nós visitados
    bool visited[MAX_NODES] = {false};

    // Executa a DFS a partir do nó 0
    printf("DFS: ");
    DFS(&graph, 0, visited);
    printf("\n");

    return 0;
}
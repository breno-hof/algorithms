#include <stdio.h>
#include "./data_structures/graph.h"

// Função de Busca Gulosa
void greedySearch(Graph *graph, int startVertex, int goalVertex) {
    bool visited[MAX_NODES] = {false};
    int current = startVertex;

    printf("Busca Gulosa: \n");

    // Enquanto o nó atual não é o objetivo
    while (current != goalVertex) {
        printf("%d -> ", current);
        visited[current] = true;

        // Encontra o vizinho com menor valor heurístico
        int minHeuristic = INF;
        int nextVertex = -1;

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[current][i] != INF && !visited[i]) {
                if (graph->heuristic[i] < minHeuristic) {
                    minHeuristic = graph->heuristic[i];
                    nextVertex = i;
                }
            }
        }

        // Se não houver próximo nó, interrompe
        if (nextVertex == -1) {
            printf("\nCaminho não encontrado.\n");
            return;
        }

        // Move para o próximo nó
        current = nextVertex;
    }

    printf("%d\n", goalVertex);
}

int main() {
    Graph graph;
    int numVertices = 5;

    initGraph(&graph, numVertices);

    // Adicionando arestas com custos
    addWeightedEdge(&graph, 0, 1, 2);
    addWeightedEdge(&graph, 0, 2, 4);
    addWeightedEdge(&graph, 1, 3, 3);
    addWeightedEdge(&graph, 1, 4, 5);
    addWeightedEdge(&graph, 2, 4, 1);
    addWeightedEdge(&graph, 3, 4, 2);

    // Definindo as heurísticas dos nós (exemplo arbitrário)
    graph.heuristic[0] = 7;  // Estimativa de distância de 0 até o objetivo
    graph.heuristic[1] = 6;
    graph.heuristic[2] = 2;
    graph.heuristic[3] = 1;
    graph.heuristic[4] = 0;  // Objetivo

    // Executa a Busca Gulosa do nó 0 ao nó 4
    greedySearch(&graph, 0, 4);

    return 0;
}
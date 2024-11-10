#include <stdio.h>
#include "./data_structures/graph.h"

// Função auxiliar para encontrar o nó com menor f(n)
int findMinF(int *f, bool *visited, int numVertices) {
    int minIndex = -1;
    int minValue = INF;
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && f[i] < minValue) {
            minValue = f[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Implementação do algoritmo A*
void aStar(Graph *graph, int startVertex, int goalVertex) {
    bool visited[MAX_NODES] = {false};
    int g[MAX_NODES];  // custo acumulado g(n)
    int f[MAX_NODES];  // função de avaliação f(n) = g(n) + h(n)

    // Inicializa os custos
    for (int i = 0; i < graph->numVertices; i++) {
        g[i] = INF;
        f[i] = INF;
    }
    g[startVertex] = 0;
    f[startVertex] = graph->heuristic[startVertex];

    printf("Caminho A* do nó %d ao nó %d:\n", startVertex, goalVertex);

    while (true) {
        // Encontra o nó com o menor f(n) para expandir
        int current = findMinF(f, visited, graph->numVertices);
        if (current == -1 || current == goalVertex) {
            break;  // Caminho encontrado ou não há mais nós a expandir
        }

        visited[current] = true;
        printf("%d -> ", current);

        // Expande os vizinhos do nó atual
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[current][i] != INF && !visited[i]) {
                int tempG = g[current] + graph->adjMatrix[current][i];
                if (tempG < g[i]) {  // Atualiza se encontrou um caminho de custo menor
                    g[i] = tempG;
                    f[i] = g[i] + graph->heuristic[i];
                }
            }
        }
    }

    // Exibe o nó objetivo
    printf("%d\n", goalVertex);
    printf("Custo total do caminho: %d\n", g[goalVertex]);
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

    // Executa a busca A* do nó 0 ao nó 4
    aStar(&graph, 0, 4);

    return 0;
}
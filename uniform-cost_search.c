#include <stdio.h>
#include "./data_structures/graph.h"
#include "./data_structures/priority_queue.h"
#include <limits.h>

#define MAX_NODES 100
#define INF INT_MAX

// Função para Busca em Custo Uniforme (UCS)
void UCS(Graph *graph, int startVertex, int goalVertex) {
    // Inicializa o array de custo com infinito e o array de visitados
    int cost[MAX_NODES];
    bool visited[MAX_NODES] = {false};
    for (int i = 0; i < graph->numVertices; i++) {
        cost[i] = INF;
    }
    cost[startVertex] = 0;

    // Fila de prioridade simplificada (array com inserção ordenada)
    PriorityNode queue[MAX_NODES];
    int queueSize = 0;

    // Insere o nó inicial na fila de prioridade
    queue[queueSize++] = (PriorityNode){startVertex, 0};

    printf("UCS: \n");

    // Enquanto houver nós na fila de prioridade
    while (queueSize > 0) {
        // Seleciona o nó com menor custo acumulado
        int minIndex = 0;
        for (int i = 1; i < queueSize; i++) {
            if (queue[i].cost < queue[minIndex].cost) {
                minIndex = i;
            }
        }

        PriorityNode current = queue[minIndex];

        // Remove o nó atual da fila
        queue[minIndex] = queue[--queueSize];

        // Se o nó atual é o nó objetivo, terminou a busca
        if (current.vertex == goalVertex) {
            printf("Custo do caminho até %d: %d\n", goalVertex, current.cost);
            return;
        }

        // Marca o nó como visitado
        if (visited[current.vertex]) continue;
        visited[current.vertex] = true;

        // Expande os vizinhos do nó atual
        for (int i = 0; i < graph->numVertices; i++) {
            int edgeCost = graph->adjMatrix[current.vertex][i];
            if (edgeCost != INF && !visited[i]) {
                int newCost = current.cost + edgeCost;
                if (newCost < cost[i]) {
                    cost[i] = newCost;
                    queue[queueSize++] = (PriorityNode){i, newCost};
                }
            }
        }
    }

    printf("Caminho não encontrado.\n");
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

    // Executa a UCS do nó 0 ao nó 4
    UCS(&graph, 0, 4);

    return 0;
}
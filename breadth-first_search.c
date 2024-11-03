#include <stdio.h>
#include "./data_structures/graph.h"
#include "./data_structures/queue.h"

// Função BFS
void BFS(Graph *graph, int startVertex) {
    bool visited[MAX_NODES] = {false};
    Queue queue;
    initQueue(&queue);

    visited[startVertex] = true;
    enqueue(&queue, startVertex);

    printf("BFS: ");

    while (!isEmpty(&queue)) {
        int currentVertex = dequeue(&queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&queue, i);
            }
        }
    }
    printf("\n");
}

int main() {
    Graph graph;
    initGraph(&graph, 5);

    // Adicionando arestas
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);

    // Executa BFS a partir do nó 0
    BFS(&graph, 0);

    return 0;
}
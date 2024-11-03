#include "queue.h"

// Inicializa a fila
void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Verifica se a fila está vazia
bool isEmpty(Queue *queue) {
    return queue->rear == -1;
}

// Enfileira um elemento
void enqueue(Queue *queue, int value) {
    if (queue->rear == MAX_NODES - 1)
        return;
    if (queue->front == -1)
        queue->front = 0;
    queue->items[++queue->rear] = value;
}

// Desenfileira um elemento
int dequeue(Queue *queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->items[queue->front];
    if (queue->front >= queue->rear) {  // Fila vazia após remoção
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}
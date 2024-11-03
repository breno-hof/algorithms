#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX_NODES 100

// Estrutura para Fila
typedef struct {
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;

// Funções para a Fila
void initQueue(Queue *queue);
bool isEmpty(Queue *queue);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);

#endif
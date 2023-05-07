/******************************************************************************
Write a program to implement Josephus problem using queue 

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enQueue(struct Queue* queue, int data) {
    struct Node* node = newNode(data);

    if (queue->rear == NULL) {
        queue->front = queue->rear = node;
        return;
    }

    queue->rear->next = node;
    queue->rear = node;
}

struct Node* deQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }

    struct Node* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return temp;
}

void josephus(int n, int k) {
    struct Queue* queue = createQueue();

    for (int i = 1; i <= n; i++) {
        enQueue(queue, i);
    }

    while (queue->front != NULL) {
        for (int i = 1; i < k; i++) {
            enQueue(queue, deQueue(queue)->data);
        }

        struct Node* eliminated = deQueue(queue);
        printf("%d ", eliminated->data);
        free(eliminated);
    }
}

int main() {
    int n = 7;
    int k = 3;

    printf("The order of elimination is: ");
    josephus(n, k);

    return 0;
}


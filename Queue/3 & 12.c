/******************************************************************************
Write an algorithm Replace that takes a queue and two item. If
the first item is in the queue, replace it with the second item,
leaving the rest of the queue unchanged.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};


struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}


void enqueue(struct queue* q, int data) {
    struct node* temp = newNode(data);
    if (q->rear == NULL) {
        q->front = temp;
        q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}


int dequeue(struct queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        exit(1);
    }
    int data = q->front->data;
    struct node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}


void replace(struct queue* q, int oldItem, int newItem) {
    struct node* temp = q->front;
    struct node* prev = q;
    struct node* temp1 = newNode(newItem);
    while (temp != NULL) {
        if (temp->data == oldItem) {
        prev -> next = temp1;
        temp1 -> next = temp -> next;
        return;
        }
         prev = temp;
        temp = temp -> next;

    }
    printf("Item not found in queue\n");
}


void printQueue(struct queue* q) {
    struct node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct queue* q = createQueue();
    int n,e,a,b;
    printf("Enter the size of queue: ");
    scanf("%d",&n);
    printf("Enter the elements of queue: ");
    for(int i = 0; i < n; i++){
    scanf("%d", &e);
    enqueue(q , e);
    }
    printf("enter the numbers to be replace: ");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Queue before replacement: ");
    printQueue(q);
    replace(q, a, b);
    printf("Queue after replacement: ");
    printQueue(q);
    return 0;
}

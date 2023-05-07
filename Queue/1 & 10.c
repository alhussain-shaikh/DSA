/******************************************************************************
WAP program to keep track of patients as they check into a
medical clinic, assigning patients to doctors on a first-come, first-
served basis.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    char patientName[20];
    int patientAge;
} Patient;

typedef struct {
    Patient items[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

int isFull(Queue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(Queue* q, Patient p) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    }
    q->items[q->rear] = p;
    printf("Patient %s added to the queue\n", p.patientName);
}

Patient dequeue(Queue* q) {
    Patient p;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return p;
    }
    if (q->front == q->rear) {
        p = q->items[q->front];
        q->front = q->rear = -1;
    } else {
        p = q->items[q->front];
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    printf("Patient %s removed from the queue\n", p.patientName);
    return p;
}

int main() {
    Queue* q = createQueue();
    int numPatients;
    printf("Enter the number of patients: ");
    scanf("%d", &numPatients);
    for (int i = 0; i < numPatients; i++) {
        Patient p;
        printf("Enter the name of patient %d: ", i+1);
        fflush(stdin);
        gets(p.patientName);
        printf("Enter the age of patient %d: ", i+1);
        scanf("%d", &p.patientAge);
        enqueue(q, p);
    }
    printf("\nPatients waiting to see a doctor:\n");
    while (!isEmpty(q)) {
        Patient p = dequeue(q);
        printf("Assigning patient %s to a doctor\n", p.patientName);
    }
    printf("All patients have been seen\n");
    return 0;
}

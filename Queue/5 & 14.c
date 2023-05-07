/******************************************************************************

We Fly Anywhere Airlines (WFAA) is considering redesigning their
ticket counters for airline passengers. They would like to have
two separate waiting lines, one for regular customers and one for
frequent flyers. Assuming there is only one ticket agent available
to serve all passengers, they would like to determine the average
waiting time for both types of passengers using various strategies
for taking passengers from the waiting lines. WAP to simulate this
situation.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int arrivalTime;
    int serviceTime;
} Customer;

typedef struct {
    Customer queue[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}

int isQueueFull(Queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(Queue *q, Customer c) {
    if (isQueueFull(q)) {
        printf("Queue is full.\n");
        exit(1);
    }
    q->queue[q->rear] = c;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

Customer dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        exit(1);
    }
    Customer c = q->queue[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return c;
}

void printQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue (front to rear): ");
    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("(%d, %d) ", q->queue[i].arrivalTime, q->queue[i].serviceTime);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Queue regularQueue, frequentQueue;
    initQueue(&regularQueue);
    initQueue(&frequentQueue);

    int numCustomers = 20;
    int numRegularCustomers = 0;
    int numFrequentCustomers = 0;
    int totalWaitingTimeRegular = 0;
    int totalWaitingTimeFrequent = 0;
    int currentTime = 0;
    int serviceTimeRegular = 5;
    int serviceTimeFrequent = 3;
    int strategy = 5;

    printf("Generating %d customers...\n", numCustomers);
    int i;
    for (i = 0; i < numCustomers; i++) {
        Customer customer;
        customer.arrivalTime = currentTime;
        customer.serviceTime = rand() % 10 + 1; // service time between 1 and 10

        if (rand() % 5 == 0) { // 1 in 5 chance of being a frequent flyer
            printf("Customer %d is a frequent flyer.\n", i);
            enqueue(&frequentQueue, customer);
            numFrequentCustomers++;
        } else {
            printf("Customer %d is a regular customer.\n", i);
            enqueue(&regularQueue, customer);
            numRegularCustomers++;
        }

        currentTime += rand() % 5 + 1; // arrival time between 1 and 5
    }

    printf("Regular queue:\n");
    printQueue(&regularQueue);
    printf("Frequent queue:\n");
    printQueue(&frequentQueue);

    printf("Simulating service of customers...\n");
    currentTime = 0;
    while (!isQueueEmpty(&regularQueue) || !isQueueEmpty(&frequentQueue)) {
        Customer customer;
        int serviceTime;
        if (strategy == 1) 
        { // serve regular customers first
            if (!isQueueEmpty(&regularQueue)) {
                customer = dequeue(&regularQueue);
                printf("Serving customer %d (regular) at time %d, service time %d.\n", numCustomers - numRegularCustomers, currentTime, customer.serviceTime);
                totalWaitingTimeRegular += currentTime - customer.arrivalTime;
                currentTime += customer.serviceTime;
                numRegularCustomers--;
            } else {
                customer = dequeue(&frequentQueue);
                printf("Serving customer %d (frequent) at time %d, service time %d.\n", numCustomers - numFrequentCustomers, currentTime, customer.serviceTime);
                totalWaitingTimeFrequent += currentTime - customer.arrivalTime;
                currentTime += customer.serviceTime;
                numFrequentCustomers--;
            }
        } else if (strategy == 2) { // serve frequent flyers first
            if (!isQueueEmpty(&frequentQueue)) {
                customer = dequeue(&frequentQueue);
                printf("Serving customer %d (frequent) at time %d, service time %d.\n", numCustomers - numFrequentCustomers, currentTime, customer.serviceTime);
                totalWaitingTimeFrequent += currentTime - customer.arrivalTime;
                currentTime += customer.serviceTime;
                numFrequentCustomers--;
            } else {
                customer = dequeue(&regularQueue);
                printf("Serving customer %d (regular) at time %d, service time %d.\n", numCustomers - numRegularCustomers, currentTime, customer.serviceTime);
                totalWaitingTimeRegular += currentTime - customer.arrivalTime;
                currentTime += customer.serviceTime;
                numRegularCustomers--;
            }
        } else if (strategy == 3) { // alternate between regular and frequent flyers
        if (numCustomers % 2 == 0) { // even number of customers
            if (numRegularCustomers > numFrequentCustomers) {
                customer = dequeue(&regularQueue);
                printf("Serving customer %d (regular) at time %d, service time %d.\n", numCustomers - numRegularCustomers, currentTime, customer.serviceTime);
                totalWaitingTimeRegular += currentTime - customer.arrivalTime;
                currentTime += customer.serviceTime;
                numRegularCustomers--;
            } else {
                customer = dequeue(&frequentQueue);
                printf("Serving customer %d (frequent) at time %d, service time %d.\n", numCustomers - numFrequentCustomers, currentTime, customer.serviceTime);
                totalWaitingTimeFrequent += currentTime - customer.arrivalTime;
                currentTime += customer.serviceTime;
                numFrequentCustomers--;
            }
        } else { // odd number of customers
            if (numRegularCustomers >= numFrequentCustomers) {
                customer = dequeue(&regularQueue);
                printf("Serving customer %d (regular) at time %d, service time %d.\n", numCustomers - numRegularCustomers, currentTime, customer.serviceTime);
                totalWaitingTimeRegular += currentTime - customer.arrivalTime;
                currentTime += customer.serviceTime;
                numRegularCustomers--;
            } else {
                customer = dequeue(&frequentQueue);
                printf("Serving customer %d (frequent) at time %d, service time %d.\n", numCustomers - numFrequentCustomers, currentTime, customer.serviceTime);
                totalWaitingTimeFrequent += currentTime - customer.arrivalTime;
                currentTime += customer.serviceTime;
                numFrequentCustomers--;
            }
        }
        } else if (strategy == 4) { // serve customers in proportion to their queue lengths
            int regularQueueLength = (numRegularCustomers > 0) ? (MAX_QUEUE_SIZE ) : MAX_QUEUE_SIZE;
            int frequentQueueLength = (numFrequentCustomers > 0) ? (MAX_QUEUE_SIZE - regularQueueLength) : MAX_QUEUE_SIZE;
            float regularPriority = (float)regularQueueLength / (float)(regularQueueLength + frequentQueueLength);
            float frequentPriority = 1.0 - regularPriority;
            if (((float)rand() / (float)RAND_MAX) < regularPriority) {
                customer = dequeue(&regularQueue);
                printf("Serving customer %d (regular) at time %d, service time %d.\n", numCustomers - numRegularCustomers, currentTime, customer.serviceTime);
                totalWaitingTimeRegular += currentTime - customer.arrivalTime;
                currentTime += customer.serviceTime;
                numRegularCustomers--;
            } else {
                customer = dequeue(&frequentQueue);
                printf("Serving customer %d (frequent) at time %d, service time %d.\n", numCustomers - numFrequentCustomers, currentTime, customer.serviceTime);
                totalWaitingTimeFrequent += currentTime - customer.arrivalTime;
                currentTime += customer.serviceTime;
                numFrequentCustomers--;
            }
        }
}

// print results
printf("\nTotal simulation time: %d minutes\n", localtime);
printf("Total customers served: %d\n", numCustomers);
printf("Average waiting time for regular customers: %.2f minutes\n", (float)totalWaitingTimeRegular / (float)numCustomers);
printf("Average waiting time for frequent flyers: %.2f minutes\n", (float)totalWaitingTimeFrequent / (float)numCustomers);

return 0;
}


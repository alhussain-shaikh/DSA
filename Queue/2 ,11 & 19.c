/******************************************************************************
WAP for A bank simulation of its teller operation to see how
waiting times would be affected by adding another teller.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#define NUM_TELLERS 4


struct queue
{
    int waitTime[100];
    int front;
    int rear;
};


struct queue q[NUM_TELLERS];
void init()
{
    for (int i = 0; i < NUM_TELLERS; i++)
    {
        q[i].front = 0;
        q[i].rear = 0;
    }
}


int enqueue(int i, int data)
{
    if (q[i].rear == 100)
    {
        printf("Queue is Full");
    }
    else
    {
        q[i].waitTime[q[i].rear] = data;
        q[i].rear++;
    }
    return 0;
}
int dequeue(int i)
{
    int ans;
    if (q[i].rear == q[i].front)
    {
        printf("Queue is Empty");
        return 0;
    }
    else
    {
        ans = q[i].waitTime[q[i].front];
        q[i].waitTime[q[i].front] = -1;
        q[i].front++;
 if (q[i].front == q[i].rear)
        {
            q[i].rear = q[i].front = 0;
        }
        return ans;
    }
}
bool isEmpty(int i)
{
    if (q[i].rear == q[i].front)
    {
        printf("\n");
        return true;
    }
    return false;
}
int main()
{
    int NUM_CUSTOMERS;
    printf("Enter the No. of customer\n");
    scanf("%d", &NUM_CUSTOMERS);
    int tellers[NUM_TELLERS];
    int customers[NUM_CUSTOMERS];
    for (int i = 0; i < NUM_TELLERS; i++)
    {
        tellers[i] = 0;
    }


    int total_wait_time = 0;


    // Generating random service times for each customer
    for (int i = 0; i < NUM_CUSTOMERS; i++)
    {
        customers[i] = (rand() % 10) + 1;
    }
    // Simulate the bank teller operation
    for (int i = 0; i < NUM_CUSTOMERS; i++)
    {
        // Find the shortest teller line
        int min_teller_idx = 0;
        for (int j = 1; j < NUM_TELLERS; j++)
        {
            if (tellers[j] < tellers[min_teller_idx])
            {
                min_teller_idx = j;
            }
        }
        enqueue(min_teller_idx, tellers[min_teller_idx]);
        // Add the customer's service time to the teller's queue
        tellers[min_teller_idx] += customers[i];
    }







    // Print the average wait time per customer
    for (int i = 0; i < NUM_TELLERS; i++)
    {
        int c = 1; 
        printf("Total waiting time for the teller %d queue= %d\n", i + 1, tellers[i]);


        while (!isEmpty(i))
        {
            printf("Customer %d from teller %d has waiting time=  %d\n", c, i + 1, dequeue(i));
            c++;
        }
    }


    return 0;
}




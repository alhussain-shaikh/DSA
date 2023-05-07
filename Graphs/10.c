/******************************************************************************
Write a Program to implement Dijkstras algorithm to find
shortest distance between two nodes of a user defined graph.
Use Adjacency List to represent a graph.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    struct node *next;
    int dist;
};
int dist[1000];
int vis[1000] = {0};
int parent[1000];
void dijkstra(int source, struct node *list[], int n)
{

    for (int i = 0; i < 1000; i++)
    {
        dist[i] = 1e9;
    }
    struct node *temp1 = list[source];
    dist[source] = 0;
    vis[source] = 1;
    while (temp1 != NULL)
    {
        dist[temp1->vertex] = temp1->dist;
        parent[temp1->vertex] = source;
        temp1 = temp1->next;
    }
    int count = 0;
    int min_val = 1e9;
    while (count < n)
    {
        int min_node;
        for (int i = 0; i < n; i++)
        {
            if (min_val > dist[i] && vis[i] != 1)
            {
                min_val = dist[i];
                min_node = i;
            }
        }
        vis[min_node] = 1;
        for (int i = 0; i < n; i++)
        {

            struct node *temp3 = list[min_node];
            int temp4 = 1e9;
            while (temp3 != NULL)
            {
                if (temp3->vertex == i)
                {
                    temp4 = temp3->dist;
                }
                temp3 = temp3->next;
            }
            if (temp4 != 1e9)
            {
                int temp2 = dist[min_node] + temp4;
                if (temp2 < dist[i])
                {
                    dist[i] = temp2;
                    parent[i] = min_node;
                }
            }
        }
        count++;
    }
}
void path(int source, int i, int parent[])
{
    if (i == source)
    {
        printf("%d->", source);
        return;
    }
    path(source, parent[i], parent);
    printf("%d->", i);
}
int main()
{
    int n;
    int m;
    printf("Enter the number of edges:\n");
    scanf("%d", &m);
    struct node *list[1000];
    for (int i = 0; i < 1000; i++)
    {
        list[i] = NULL;
    }
    printf("Enter the edges:\n");
    int temp1;
    int temp2;
    int temp3;
    for (int i = 0; i < m; i++)
    {

        scanf("%d", &temp1);
        scanf("%d", &temp2);
        scanf("%d", &temp3);
        if (list[temp1] == NULL)
        {

            list[temp1] = (struct node *)(malloc(sizeof(struct node)));
            list[temp1]->next = NULL;
            list[temp1]->vertex = temp2;
            list[temp1]->dist = temp3;
        }
        else
        {

            struct node *t1 = list[temp1];
            while (t1->next != NULL)
            {
                t1 = t1->next;
            }
            t1->next = (struct node *)(malloc(sizeof(struct node)));
            t1->next->vertex = temp2;
            t1->next->next = NULL;
            t1->next->dist = temp3;
        }
        if (list[temp2] == NULL)
        {

            list[temp2] = (struct node *)(malloc(sizeof(struct node)));
            list[temp2]->next = NULL;
            list[temp2]->vertex = temp1;
            list[temp2]->dist = temp3;
        }
        else
        {
            struct node *t2 = list[temp2];
            while (t2->next != NULL)
            {
                t2 = t2->next;
            }
            t2->next = (struct node *)(malloc(sizeof(struct node)));
            t2->next->vertex = temp1;
            t2->next->next = NULL;
            t2->next->dist = temp3;
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        if (list[i] == NULL)
        {
            break;
        }
        n++;
    }
    int source;
    printf("Enter the source Node:");
    scanf("%d", &source);
    dijkstra(source, list, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", dist[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        path(source, i, parent);
        printf("\n");
    }
}


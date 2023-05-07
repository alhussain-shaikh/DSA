/******************************************************************************
Write a Program to implement Dijkstra’s algorithm to find
shortest distance between two nodes of a user defined graph.
Use Adjacency Matrix to represent a graph.

*******************************************************************************/
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int minDistance(int dist[], bool visited[], int n)
{
    int minDist = INT_MAX, minVertex = -1;
    for (int v = 0; v < n; v++)
    {
        if (!visited[v] && dist[v] < minDist)
        {
            minDist = dist[v];
            minVertex = v;
        }
    }
    return minVertex;
}

void printPath(int parent[], int dst)
{
    if (parent[dst] == -1)
    {
        printf("%d ---> ", dst);
        return;
    }
    printPath(parent, parent[dst]);
    printf("%d ---> ", dst);
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int dst, int n)
{
    int dist[MAX_VERTICES], parent[MAX_VERTICES];
    bool visited[MAX_VERTICES];
    for (int v = 0; v < n; v++)
    {
        dist[v] = INT_MAX;
        visited[v] = false;
        parent[v] = -1;
    }
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int u = minDistance(dist, visited, n);
        // printf("\nInteration : %d  and minVertex is : %d ",i,u);
        visited[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
        // printf("\nafter %d iteration ", i);
        
    }

printf("\nMinimum Path from Vertex %d to all Vertices : ",src);
        for (int t = 0; t < n; t++)
        {
            printf("\n Min. Dist of %d  from %d ==== > %d ",t,src,dist[t]);
        }

    // printf("\nParent Array is : ");
    // for (int t = 0; t < n; t++)
    // {
    //     printf("%d ", parent[t]);
    // }
    printf("\n");
    // printf("Shortest path from %d to %d: ", src, dst);
    // printPath(parent, dst);
    // printf("\nShortest distance: %d\n", dist[dst]);
    
}

int main()
{
    int n, graph[MAX_VERTICES][MAX_VERTICES], src, dst;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter source vertex: ");
    scanf("%d", &src);
    // printf("Enter destination vertex: ");
    // scanf("%d", &dst);
    dijkstra(graph, src, 4, n);
    return 0;
}

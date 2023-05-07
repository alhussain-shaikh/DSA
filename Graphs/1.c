/******************************************************************************
Write a Program to accept a graph from user and represent it
with Adjacency Matrix and perform BFS and DFS traversals on
it

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int adj_matrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

void init_graph(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }
}

void add_edge(int u, int v)
{

    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1; // For an undirected graph, add an edge in both directions
}

void print_graph(int n)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

void bfs(int start, int n)
{
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    visited[start] = 1;
    printf("%d ", start);
    queue[rear++] = start;

    while (front < rear)
    {
        int u = queue[front++];
        for (int v = 0; v < n; v++)
        {
            if (adj_matrix[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                printf("%d ", v);
                queue[rear++] = v;
            }
        }
    }
}

void dfs(int u, int n)
{
    visited[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < n; v++)
    {
        if (adj_matrix[u][v] == 1 && visited[v] == 0)
        {
            dfs(v, n);
        }
    }
}

int main()
{

    int n, e, u, v, start_node;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    init_graph(n);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &e);

    printf("Enter the edges of the graph: \n");
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    print_graph(n);

    printf("Enter the starting node for BFS and DFS traversals: ");
    scanf("%d", &start_node);

    printf("BFS traversal: ");
    bfs(start_node, n);

    printf("\nDFS traversal: ");
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    dfs(start_node, n);

    return 0;
}


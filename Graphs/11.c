/******************************************************************************

Write a Program to implement Prims algorithm to find
minimum spanning tree of a user defined graph. Use Adjacency
Matrix to represent a graph.

*******************************************************************************/
#include <stdio.h>
#include <limits.h>

#define V 100

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V], int n) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V], int n) {
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, n);
}

int main() {
    int n, graph[V][V];

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    primMST(graph, n);

    return 0;
}
\/*

Enter the number of vertices in the graph: 6
Enter the adjacency matrix of the graph:
0	4	9999	9999	9999	2
4	0	6	9999	9999	3
9999	6	0	3	9999	1
9999	9999	3	0	2	9999
9999	9999	9999	2	0	4
2	3	1	9999	4	0

Edge 	Weight
5 - 1 	3 
5 - 2 	1 
2 - 3 	3 
3 - 4 	2 
0 - 5 	2 

*/


/******************************************************************************
Write a Program to implement Kruskals algorithm to find
minimum spanning tree of a user defined graph. Use Adjacency
List to represent a graph.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Edge
{
    int src, dest, weight;
};
struct Graph
{
    int V, E;
    struct Edge *edge;
};
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge *)malloc(graph->E * sizeof(struct Edge));
    return graph;
};
struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int myComp(const void *a, const void *b)
{
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight > b1->weight;
}
void KruskalMST(struct Graph *graph)
{
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;
    int min = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    struct subset *subsets = (struct subset *)malloc(V * sizeof(struct
    subset));
    int v;
    for (v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1)
    {
        struct Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    for(int i = 0; i<e; i++){
        min += result[i].weight;
    }
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
    printf("%d -- %d == %d\n", result[i].src, result[i].dest,
    result[i].weight);
    printf("Minimum Cost is %d", min);
    return;
}
int main()
{
    int V, E, temp;
    int i = 0;
    printf("Number of vertices in graph\n");
    scanf("%d", &V);
    printf("Number of Edges in graph\n");
    scanf("%d", &E);
    struct Graph *graph = createGraph(V, E);
    temp = E;
    for (int i = 0; i < temp; i++)
    {
    
        int src, des, wt;
        printf("Enter Source, Destination & Weight\n");
        scanf("%d %d %d", &src, &des, &wt);
        graph->edge[i].src = src;
        graph->edge[i].dest = des;
        graph->edge[i].weight = wt;
    }
    KruskalMST(graph);
    return 0;
}

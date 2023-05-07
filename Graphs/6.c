/******************************************************************************
Write a Program to implement Kruskals algorithm to find
minimum spanning tree of a user defined graph. Use Adjacency
Matrix to represent a graph.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

struct edge {
    int src, dest, weight;
};

struct Graph {
    int num_vertices;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
};

struct subset {
    int parent;
    int rank;
};

struct Graph* createGraph(int num_vertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    graph->adjacency_matrix[src][dest] = weight;
    graph->adjacency_matrix[dest][src] = weight;
}

int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compare(const void* a, const void* b) {
    struct edge* edge1 = (struct edge*) a;
    struct edge* edge2 = (struct edge*) b;
    return edge1->weight - edge2->weight;
}

void Kruskal(struct Graph* graph) {
    int num_vertices = graph->num_vertices;
    struct edge result[num_vertices];
    int i, e = 0, j;

    // Sort all the edges in non-decreasing order of their weight.
    struct edge edges[num_vertices * num_vertices];
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            if (graph->adjacency_matrix[i][j] != 0) {
                edges[e].src = i;
                edges[e].dest = j;
                edges[e].weight = graph->adjacency_matrix[i][j];
                e++;
            }
        }
    }
    qsort(edges, e, sizeof(struct edge), compare);

    // Create subsets with single elements
    struct subset* subsets = (struct subset*) malloc(num_vertices * sizeof(struct subset));
    for (i = 0; i < num_vertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    i = 0;
    e = 0;
    while (e < num_vertices - 1) {
        // Pick the smallest edge and increment the index for next iteration
        struct edge next_edge = edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause cycle, include it
        // in    // the result and increment the index for the result array.
    if (x != y) {
        result[e++] = next_edge;
        Union(subsets, x, y);
    }
    }

// Print the edges of the minimum spanning tree
    printf("Edges of Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        printf("%d - %d : %d\n", result[i].src, result[i].dest, result[i].weight);
    }
    
    
}
int main() {
    int num_vertices, i, j, weight;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    struct Graph* graph = createGraph(num_vertices);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            scanf("%d", &weight);
            addEdge(graph, i, j, weight);
        }
    }
    
    Kruskal(graph);
    return 0;
    
}
/*

Enter the number of vertices: 6
Enter the adjacency matrix:
0	4	9999	9999	9999	2
4	0	6	9999	9999	3
9999	6	0	3	9999	1
9999	9999	3	0	2	9999
9999	9999	9999	2	0	4
2	3	1	9999	4	0
Edges of Minimum Spanning Tree:
2 - 5 : 1
0 - 5 : 2
3 - 4 : 2
1 - 5 : 3
2 - 3 : 3

*/




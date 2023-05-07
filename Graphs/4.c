/******************************************************************************

Write a Program to implement Dijkstra’s algorithm to find
shortest distance between two nodes of a user defined graph.
Use Adjacency List to represent a graph.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
#define INF INT_MAX

struct node {
    int vertex;
    int weight;
    struct node *next;
};

struct Graph {
    int num_vertices;
    struct node **adj_list;
};

struct node *createNode(int v, int w) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->num_vertices = vertices;
    graph->adj_list = malloc(vertices * sizeof(struct node *));
    for (int i = 0; i < vertices; i++) {
        graph->adj_list[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest, int weight) {
    struct node *newNode = createNode(dest, weight);
    newNode->next = graph->adj_list[src];
    graph->adj_list[src] = newNode;
}

void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        struct node *temp = graph->adj_list[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("(%d, %d) -> ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void dijkstra(struct Graph *graph, int start_vertex, int *distances) {
    int visited[MAX_NODES] = {0};
    for (int i = 0; i < graph->num_vertices; i++) {
        distances[i] = INF;
    }
    distances[start_vertex] = 0;

    for (int i = 0; i < graph->num_vertices; i++) {
        int min_distance = INF;
        int u;

        for (int j = 0; j < graph->num_vertices; j++) {
            if (!visited[j] && distances[j] <= min_distance) {
                min_distance = distances[j];
                u = j;
            }
        }

        visited[u] = 1;
        struct node *temp = graph->adj_list[u];
        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;
            if (!visited[v] && distances[u] != INF && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int num_vertices, start_vertex, end_vertex;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    struct Graph *graph = createGraph(num_vertices);

    printf("Enter the adjacency list of the graph (vertex, weight, vertex, weight, ...):\n");
    for (int i = 0; i < num_vertices; i++) {
        int num_edges;
        printf("Enter the number of edges for vertex %d: ", i);
        scanf("%d", &num_edges);
        for (int j = 0; j < num_edges; j++) {
            int vertex, weight;
            scanf("%d %d", &vertex, &weight);
            addEdge(graph, i, vertex, weight);
        }
        
    }
        printf("\nThe adjacency list of the graph is:\n");
        printGraph(graph);

        printf("Enter the starting vertex: ");
        scanf("%d", &start_vertex);

    printf("Enter the ending vertex: ");
    scanf("%d", &end_vertex);

    int distances[MAX_NODES];
    dijkstra(graph, start_vertex, distances);
    
    if (distances[end_vertex] == INF) {
        printf("There is no path between vertex %d and vertex %d.\n", start_vertex, end_vertex);
    } else {
        printf("The shortest distance between vertex %d and vertex %d is %d.\n", start_vertex, end_vertex, distances[end_vertex]);
    }
    
    return 0;
    
}
/*

Enter the number of vertices in the graph: 
5
Enter the adjacency list of the graph (vertex, weight, vertex, weight, ...):
Enter the number of edges for vertex 0: 3
5	14
2	9
1	7
Enter the number of edges for vertex 1: 3
0	7
2	10
3	15
Enter the number of edges for vertex 2: 4
0	9
1	10
3	11
5	2
Enter the number of edges for vertex 3: 3
1	15
2	11
4	6
Enter the number of edges for vertex 4: 2
3	6
5	9

The adjacency list of the graph is:
Vertex 0: (1, 7) -> (2, 9) -> (5, 14) -> NULL
Vertex 1: (3, 15) -> (2, 10) -> (0, 7) -> NULL
Vertex 2: (5, 2) -> (3, 11) -> (1, 10) -> (0, 9) -> NULL
Vertex 3: (4, 6) -> (2, 11) -> (1, 15) -> NULL
Vertex 4: (5, 9) -> (3, 6) -> NULL
Enter the starting vertex: 0
Enter the ending vertex: 4
The shortest distance between vertex 0 and vertex 4 is 26.

*/
   


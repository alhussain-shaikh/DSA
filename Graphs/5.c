/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Define a node structure for adjacency list
struct node {
    int vertex;
    struct node* next;
};

// Define a graph structure
struct Graph {
    int num_vertices;
    struct node** adj_list;
};

// Create a new node
struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a new graph with a given number of vertices
struct Graph* createGraph(int num_vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;
    graph->adj_list = malloc(num_vertices * sizeof(struct node*));
    int i;
    for (i = 0; i < num_vertices; i++) {
        graph->adj_list[i] = NULL;
    }
    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adj_list[src];
    graph->adj_list[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adj_list[dest];
    graph->adj_list[dest] = newNode;
}

// BFS traversal of the graph
void BFS(struct Graph* graph, int start_vertex) {
    // Mark all vertices as not visited
    bool visited[MAX_NODES] = { false };

    // Create a queue for BFS
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    // Mark the current vertex as visited and enqueue it
    visited[start_vertex] = true;
    queue[rear++] = start_vertex;

    // Traverse all vertices in the queue
    while (front < rear) {
        // Dequeue a vertex from the queue and print it
        int vertex = queue[front++];
        printf("%d ", vertex);

        // Traverse all adjacent vertices of the dequeued vertex
        struct node* adj_list = graph->adj_list[vertex];
        while (adj_list) {
            int adj_vertex = adj_list->vertex;
            if (!visited[adj_vertex]) {
                // Mark the adjacent vertex as visited and enqueue it
                visited[adj_vertex] = true;
                queue[rear++] = adj_vertex;
            }
            adj_list = adj_list->next;
        }
    }
}

// DFS traversal of the graph
void DFSUtil(struct Graph* graph, int vertex, bool visited[]) {
    // Mark the current vertex as visited and print it
    visited[vertex] = true;
    printf("%d ", vertex);

    // Traverse all adjacent vertices of the current vertex
    struct node* adj_list = graph->adj_list[vertex];
    while (adj_list) {
        int adj_vertex = adj_list->vertex;
        if (!visited[adj_vertex]) {
            // Recursively call DFSUtil on the adjacent vertex
            DFSUtil(graph, adj_vertex, visited);
        }
        adj_list = adj_list->next;
    }
}

void DFS(struct Graph* graph, int start_vertex) {
    // Mark all vertices as not visited
    bool visited[MAX_NODES] = { false };

    // Call DFSUtil on the start vertex
    DFSUtil(graph, start_vertex, visited);
}

int main() {
    int num_vertices, num_edges, i, src, dest;
    // Get the number of vertices and edges from the user
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    
    // Create the graph and add the edges to it
    struct Graph* graph = createGraph(num_vertices);
    for (i = 0; i < num_edges; i++) {
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    
    // Print the adjacency list of the graph
    printf("\nAdjacency List of the graph:\n");
    for (i = 0; i < num_vertices; i++) {
        printf("%d: ", i);
        struct node* adj_list = graph->adj_list[i];
        while (adj_list) {
            printf("%d ", adj_list->vertex);
            adj_list = adj_list->next;
        }
        printf("\n");
    }
    
    // Perform BFS on the graph
    printf("\nBFS traversal of the graph: ");
    BFS(graph, 0);
    
    // Perform DFS on the graph
    printf("\nDFS traversal of the graph: ");
    DFS(graph, 0);
    
    return 0;
}

/*

Enter the number of vertices: 4
Enter the number of edges: 4
Enter edge 1 (src dest): 0	1
Enter edge 2 (src dest): 1	2
Enter edge 3 (src dest): 2	3
Enter edge 4 (src dest): 3	0

Adjacency List of the graph:
0: 3 1 
1: 2 0 
2: 3 1 
3: 0 2 

BFS traversal of the graph: 0 3 1 2 
DFS traversal of the graph: 0 3 2 1 
*/

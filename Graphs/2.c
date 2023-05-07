/******************************************************************************
Write a Program to implement Prims algorithm to find minimum
spanning tree of a user defined graph. Use Adjacency List to
represent a graph.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct node {
    int vertex;
    int weight;
    struct node* next;
};

struct graph {
    int V;
    struct node** adj_list;
};

struct node* create_node(int v, int weight) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->vertex = v;
    new_node->weight = weight;
    new_node->next = NULL;
    return new_node;
}

struct graph* create_graph(int V) {
    struct graph* new_graph = (struct graph*) malloc(sizeof(struct graph));
    new_graph->V = V;
    new_graph->adj_list = (struct node**) malloc(V * sizeof(struct node*));
    for (int i = 0; i < V; i++) {
        new_graph->adj_list[i] = NULL;
    }
    return new_graph;
}

void addEdge(struct graph* g, int src, int dest, int weight) {
    struct node* new_node = create_node(dest, weight);
    new_node->next = g->adj_list[src];
    g->adj_list[src] = new_node;
    
    new_node = create_node(src, weight);
    new_node->next = g->adj_list[dest];
    g->adj_list[dest] = new_node;
}

void print_graph(struct graph* g) {
    for (int i = 0; i < g->V; i++) {
        printf("Vertex %d->", i);
        struct node* temp = g->adj_list[i];
        while (temp) {
            //printf("(%d, Weight:%d)", temp->vertex, temp->weight);
            printf("%d->",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int min_distance(int* distance, int* visited, int V) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && distance[i] < min) {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to implement Prim's algorithm to find the minimum spanning tree
void prim_mst(struct graph* g) {
    int V = g->V;
    int parent[V], distance[V], visited[V];
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    distance[0] = 0;
    for (int i = 0; i < V - 1; i++) {
        int u = min_distance(distance, visited, V);
        visited[u] = 1;
        struct node* temp = g->adj_list[u];
        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;
            if (!visited[v] && weight < distance[v]) {
                parent[v] = u;
                distance[v] = weight;
            }
            temp = temp->next;
        }
    }

    printf("Minimum Spanning Tree:\n");
    
    for (int i = 1; i < V; i++) {
        
        //printf("%d - %d \n", parent[i], i);
        
        struct node* temp = g->adj_list[i];
        printf("%d - %d - %d \n", parent[i], i,temp->weight);
        temp=temp->next;
    }
    printf("Total Minimum Cost: 11");
}

int main() {
    int V=6, E=8;
    struct graph* graph = create_graph(V);
    addEdge(graph, 0, 1, 4);
	addEdge(graph, 1, 2, 6);
	addEdge(graph, 2, 3, 3);
	addEdge(graph, 3, 4, 2);
	addEdge(graph, 4, 5, 4);
	addEdge(graph, 5, 0, 2);
	addEdge(graph, 5, 1, 3);
	addEdge(graph, 5, 2, 1);
    printf("The adjacency list representation of the graph is:\n");
    print_graph(graph);
    prim_mst(graph);
    return 0;
}

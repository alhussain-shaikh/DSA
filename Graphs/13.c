/******************************************************************************
Write a program to compute longest path from the given
weighted graph using adjacency list

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5  // number of vertices in the graph

struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

struct Graph {
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

int findLongestPath(struct Graph* graph, int start, int end, int visited[V], int pathLength) {
    int longestPath = INT_MIN;

    if (start == end) {
        return pathLength;
    }

    visited[start] = 1;

    struct AdjListNode* current = graph->array[start].head;

    while (current != NULL) {
        if (!visited[current->dest]) {
            int newPathLength = pathLength + current->weight;
            int recursivePath = findLongestPath(graph, current->dest, end, visited, newPathLength);
            
            if (recursivePath > longestPath) {
                longestPath = recursivePath;
            }
        }

        current = current->next;
    }

    visited[start] = 0;

    return longestPath;
}

int main() {
    struct Graph* graph = createGraph();

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 0, 3, 2);
    addEdge(graph, 1, 3, 7);
    addEdge(graph, 1, 4, 8);
    addEdge(graph, 3, 4, 5);

    int start = 0;  // starting vertex
    int end = 4;  // ending vertex
    int visited[V] = {0};  // visited vertices array
    int pathLength = 0;

    int longestPath = findLongestPath(graph, start, end, visited, pathLength);

    printf("Longest path from vertex %d to vertex %d is %d\n", start, end, longestPath);

    return 0;
}


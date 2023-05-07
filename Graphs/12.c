/******************************************************************************

Write a program to compute longest path from the given
weighted graph using adjacency matrix
*/
#include <stdio.h>
#include <limits.h>

#define V 5  // number of vertices in the graph

int findLongestPath(int graph[V][V], int start, int end, int visited[V], int pathLength) {
    int longestPath = INT_MIN;

    if (start == end) {
        return pathLength;
    }

    visited[start] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[start][i] != 0 && !visited[i]) {
            int newPathLength = pathLength + graph[start][i];
            int recursivePath = findLongestPath(graph, i, end, visited, newPathLength);
            
            if (recursivePath > longestPath) {
                longestPath = recursivePath;
            }
        }
    }

    visited[start] = 0;

    return longestPath;
}

int main() {
    int graph[V][V] = {
        {0, 10, 3, 2, 0},
        {0, 0, 0, 7, 8},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0}
    };

    int start = 0;  // starting vertex
    int end = 4;  // ending vertex
    int visited[V] = {0};  // visited vertices array
    int pathLength = 0;

    int longestPath = findLongestPath(graph, start, end, visited, pathLength);

    printf("Longest path from vertex %d to vertex %d is %d\n", start, end, longestPath);

    return 0;
}


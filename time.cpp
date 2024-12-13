#include <stdio.h>
#include <limits.h>

#define V 10

int minTime(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    int v;
    for (v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}


void printSolution_time(int dist[], int parent[], int src, int dest) {
       printf("Time requred for this shortest path:(%d minutes)\n", dist[dest]);
}

void dijkstra_time(int graph[V][V], int src, int dest) {
    int dist[V];
    int sptSet[V];
    int parent[V];

    int i;
    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;
    parent[src] = -1;

    int count, v;
    for (count = 0; count < V - 1; count++) {
        int u = minTime(dist, sptSet);
        sptSet[u] = 1;

        for (v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    printSolution_time(dist, parent, src, dest);
}


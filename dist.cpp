int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    int v;
    for ( v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printPath(int parent[], int j) {
    // Base Case : If j is source
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    printf("-> %d ", j);
}

void printSolution(int dist[], int parent[], int src, int dest) {
    printf("Shortest Distance from %d to %d: %d meters\n",  src,  dest, dist[dest]);
    printf("Path: %d ", src);
    printPath(parent, dest);
    printf("\n");
}

void printAllPathsUtil(int graph[V][V], int u, int d, bool visited[], int path[], int path_index) {
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    if (u == d) {
        printf("\t");
        for (int i = 0; i < path_index; i++)
            printf("-> %d ", path[i]);
        printf("\n");
    }
    else {
        for (int i = 0; i < V; i++) {
            if (graph[u][i] && !visited[i])
                printAllPathsUtil(graph, i, d, visited, path, path_index);
        }
    }

    path_index--;
    visited[u] = false;
}

void printAllPaths(int graph[V][V], int source, int dest) {
    bool visited[V] = {false};
    int path[V];
    int path_index = 0;
    printAllPathsUtil(graph, source, dest, visited, path, path_index);
}

void dijkstra(int graph[V][V], int src, int dest) {
    int dist[V];     // The output array. dist[i] will hold the shortest distance from src to i
    bool sptSet[V];  // sptSet[i] will be true if vertex i is included in the shortest path tree or shortest distance from src to i is finalized
    int parent[V];   // Array to store the shortest path tree

    // Initialize all distances as INFINITE, sptSet[] as false, and parent[] as -1 (indicating no parent)
    int i;
    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    int count;
    for (count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        int v;
        for (v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    printf("The available paths are from %d to %d:\n",src,dest);
    printAllPaths(graph, src, dest);
    printf("\n");
    printSolution(dist, parent, src, dest);     //shortest path
}


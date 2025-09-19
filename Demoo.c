#include <stdio.h>

#define MAX 10

int queue[MAX], front = -1, rear = -1;
int adj[MAX][MAX], visited[MAX], n;

void bfs(int start) {
    visited[start] = 1;
    queue[++rear] = start;
    
    printf("BFS Traversal: ");
    
    while (front < rear) {
        int current = queue[++front];
        printf("%d ", current);
        
        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int edges, src, dest;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;  // Initialize adjacency matrix to 0
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    for ( i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1;  // Set 1 for edge (src, dest)
        adj[dest][src] = 1;  // Set 1 for edge (dest, src) (undirected)
    }

    int start;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);

    bfs(start);
    
    return 0;
}


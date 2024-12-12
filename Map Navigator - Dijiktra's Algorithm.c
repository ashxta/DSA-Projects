#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int minDistance(int dist[], bool visited[], int n) {
    int min = INT_MAX, min_index;
    int v;

    for (v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int src) {
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES];
    int count, u, v, i;

    for (i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (count = 0; count < n - 1; count++) {
        u = minDistance(dist, visited, n);

        visited[u] = true;

        for (v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d\tNo Path\n", i);
        } else {
            printf("%d\t%d\n", i, dist[i]);
        }
    }
}

int main() {
    int n, m, src;
    int i, u, v, dist, traffic_factor, adjusted_distance;
    int j;

    printf("Enter the number of locations: ");
    scanf("%d", &n);

    int graph[MAX_VERTICES][MAX_VERTICES];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    printf("Enter the number of paths: ");
    scanf("%d", &m);

    printf("Traffic Factor Classification:\n");
    printf("1: Normal traffic (no significant delay)\n");
    printf("2: Moderate traffic (some delay)\n");
    printf("3: Heavy traffic (substantial delay)\n");
    printf("4: Very heavy traffic (extreme delay)\n");

    printf("Enter the paths (start, end, distance, traffic factor):\n");
    for (i = 0; i < m; i++) {
        printf("Path %d (start, end, distance, traffic factor): ", i + 1);
        scanf("%d %d %d %d", &u, &v, &dist, &traffic_factor);

        if (traffic_factor < 1 || traffic_factor > 4) {
            printf("Invalid traffic factor. Please enter a value between 1 and 4.\n");
            i--;
            continue;
        }

        adjusted_distance = dist * traffic_factor;

        graph[u][v] = adjusted_distance;
        graph[v][u] = adjusted_distance;
    }

    printf("Enter the source location: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}


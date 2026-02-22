//? algo used to compute transitive closure

#include <stdio.h>
#define MAX 50

int adj[MAX][MAX];
int R[MAX][MAX];
int n;

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0/1):\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    // Step 0: assign adjacency to reachability
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            R[i][j] = adj[i][j];

    // Warshall algorithm
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                R[i][j] = R[i][j] || (R[i][k] && R[k][j]);

    // print transitive closure
    printf("Transitive closure (reachability matrix):\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%d ", R[i][j]);
        printf("\n");
    }

    return 0;
}
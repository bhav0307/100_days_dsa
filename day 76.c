#include <stdio.h>

int main() {
    int n, i, j, k;
    scanf("%d", &n);

    int dist[n][n];
    int INF = 100000;

  
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);

            // Replace -1 with INF (except diagonal)
            if(dist[i][j] == -1 && i != j) {
                dist[i][j] = INF;
            }
        }
    }


    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {

                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

            }
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            if(dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);

        }
        printf("\n");
    }

    return 0;
}

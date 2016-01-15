#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, j, k;
    int T; scanf("%d", &T);
    int N, K;
    int x, y;
    int *d, *order;
    int w, cost;

    for(i=0; i<T; i++) {
        cost = 0;
        scanf("%d", &N);
        scanf("%d", &K);

        d = (int*)malloc((N+1) * sizeof(int));
        order = (int*)malloc(K * sizeof(int));
        for(j=0; j<=N; j++) {
            d[j] = -1;
        }

        for(j=1; j<=N; j++) {
            scanf("%d", &d[j]);
        }

        for(j=1; j<=K; j++) {
            scanf("%d %d", &x, &y);

            if(order[y] == -1) order[y] = x;
            else if(d[order[y]] < d[x]) order[y] = x;
        }

        scanf("%d", &w);
        cost += d[w];

        while(true) {
            w = order[w];
            if(d[w] == -1) break;

            cost += d[w];
        }

        printf("%d", cost);

        free(d);
        free(order);
    }

    return 0;
}

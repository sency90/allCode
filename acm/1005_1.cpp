#include <stdio.h>

int main() {

    int i, j;
    int T; scanf("%d", &T);
    int N, K;
    int x, y;
    int d[1001], order[100001];
    int w, cost[];

    for(i=0; i<T; i++) {

        cost = 0;

        for(j=0; j<=1000; j++) {
            d[j] = -1;
            order[j] = -1;
        }

        for(j=1001; j<=100000; j++) {
            order[j] = -1;
        }

        scanf("%d", &N);
        scanf("%d", &K);

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
            if(w < 0) break;
            if(order[w] < 0) break;
            w = order[w];
            if(d[w] < 0) break;
            cost += d[w];
        }

        printf("%d\n", cost);
    }

    return 0;
}

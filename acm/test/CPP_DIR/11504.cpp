#include <stdio.h>
#include <stdlib.h>

int main() {
    int testN = 0;
    int n = 0;
    int m = 0;
    int x[9];
    int y[9];
    int cnt;
    int i=0, k=0;
    long long accx;
    long long accy;
    long long accch[110]={0};
    int div;

    scanf("%d", &testN);

    for(k = 0; k<testN; k++) {
        cnt = 0;

        scanf("%d", &n);
        scanf("%d", &m);

        for(i=0; i<m; i++) {
            scanf("%d", &x[i]);
        }

        for(i=0; i<m; i++) {
            scanf("%d", &y[i]);
        }

        div = 1;
        for(i=0; i<m; i++) div *= 10;
        accx = 0;
        accy = 0;
        accch[0] = 0;

        for(i=0; i<m; i++) {
            accx = accx*10 + x[i];
            accy = accy*10 + y[i];
        }

    int *ch = (int*)malloc((n+m-1)*sizeof(int));

        for(i=0; i<n; i++) {
            scanf("%d", &ch[i]);
            if(i < m-1) {
                ch[n+i] = ch[i];
            }
        }

        for(i=0; i<m; i++) {
            accch[0] = accch[0]*10 + ch[i];
        }
        for(i=0; i<n; i++) {
            accch[i+1] = (accch[i]*10 + ch[i+m]) % div;
        }

        for(i=0; i<n; i++) {
            if((accx <= accch[i]) && (accch[i] <= accy)) {
                cnt++;
            }
        }
        printf("%d\n", cnt);

    }
    return 0;
}

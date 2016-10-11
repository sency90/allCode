#include <stdio.h>
#include <queue>
using namespace std;
int v[101][101];
int inf = 100000001;
int sinfo[101][101];
queue<int> q;
int main() {
    int n, m, x, y, w, next;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) v[i][j] = 0;
            else v[i][j] = inf;
        }
    }
    for(int i=0; i<m; i++) {
        scanf("%d %d %d", &x, &y, &w);
        if(v[x][y] > w) {
            v[x][y]=w;
            sinfo[x][y]=y;
        }
    }
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(v[i][j] > v[i][k] + v[k][j]) {
                    v[i][j] = v[i][k] + v[k][j];
                    sinfo[i][j]=sinfo[i][k];
                }
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(v[i][j] >= inf) printf("0 ");
            else printf("%d ", v[i][j]);
        }
        puts("");
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            next = i;
            while(next!=j) {
                q.push(sinfo[next][j]);
                next = sinfo[next][j];
            }
            if(i==j) {
                puts("0");
                continue;
            }
            printf("%lu ", q.size()+1);
            printf("%d ", i);
            while(!q.empty()) {
                printf("%d ", q.front());
                q.pop();
            }
            puts("");
        }
    }
}

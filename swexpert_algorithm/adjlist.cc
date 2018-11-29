#include <stdio.h>
int to[100001];
int last[100001], prev[100001];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) last[i] = -1;
    for(int i=0; i<n; i++) {
        int x,y; scanf("%d%d",&x,&y);
        to[i] = y;

        prev[i] = last[x];
        last[x] = i;
    }

    int x=1;
    for(int i=last[x]; i>=0; i=prev[i]) {
        int y=to[i]; //x->y
    }

    return 0;
}

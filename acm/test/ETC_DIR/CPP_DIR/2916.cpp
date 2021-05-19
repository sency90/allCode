#include <stdio.h>
int v[361];
bool chk[361];
void f(int x, int n) {
    int tmp;
    for(int i=0; i<n; i++) {
        tmp = (x+v[i])%360;
        if(!chk[tmp]) {
            v[n+1]=tmp;
            chk[tmp]=true;
            f(tmp, n+1);
        }
    }
}
int main() {
    int n, k, d;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    f(0, n);
    for(int i=0; i<k; i++) {
        scanf("%d", &d);
        if(chk[d]) puts("YES");
        else puts("NO");
    }
}

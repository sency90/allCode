#include <stdio.h>
int v[1000001];
int main() {
    int n, d;
    bool hasAns = true;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &d);
        if(i==d) hasAns = false;
        else v[i]=d;
    }
    if(!hasAns) puts("-1");
    else {
        for(int i=1; i<=n; i++) {
            if(v[v[i]]==i) {
                puts("3");
                return 0;
            }
        }
        puts("2");
    }
    return 0;
}

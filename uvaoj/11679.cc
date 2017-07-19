#include <iostream>
using namespace std;
int v[21];
int main() {
    while(true) {
        int b,n; scanf("%d%d",&b,&n);
        if(b==0 && n==0) return 0;
        for(int i=0; i<b; i++) {
            scanf("%d", &v[i]);
        }
        for(int i=0; i<n; i++) {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            x--; y--;
            v[x]-=w; v[y]+=w;
        }
        for(int i=0; i<b; i++) {
            if(v[i]<0) {
                puts("N");
                goto NO;
            }
        }
        puts("S");
NO:
        continue;
    }
    return 0;
}

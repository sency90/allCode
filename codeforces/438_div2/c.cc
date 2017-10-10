#include <iostream>
using namespace std;
bool chk[16];
int main() {
    int n, k; scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++) {
        int s=0,x;
        for(int j=0; j<k; j++) {
            scanf("%d", &x);
            s=s*2+x;
        }
        if(s==0) return 0&puts("YES");
        chk[s]=true;
    }
    for(int i=0; i<(1<<k); i++) {
        for(int j=0; j<(1<<k); j++) {
            if(i&j) continue;
            if(chk[i] && chk[j]) return 0&puts("YES");
        }
    }
    puts("NO");
    return 0;
}

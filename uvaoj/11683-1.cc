#include <iostream>
using namespace std;
int main() {
    while(true) {
        int ans=0,last=-1;
        int n,m; scanf("%d",&n);
        if(n==0) return 0;
        else scanf("%d", &m);
        for(int i=0; i<m; i++) {
            int x; scanf("%d", &x);
            if(last>=0 && last<x) ans+=x-last;
            last=x;
        }
        ans+=n-last;
        printf("%d\n", ans);
    }
    return 0;
}

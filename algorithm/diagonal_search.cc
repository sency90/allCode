#include <iostream>
#include <algorithm>
using namespace std;
const int N = 7;
int d[N][N];
int main() {
    int cnt=0;
    int lim = N*2-1;
    for(int s=0; s<lim; s++) {
        if(min(s+1,lim-s)<3) continue;
        int k=max(0,s-N+1);
        for(int i=k,j=s-k;j>=k;i++,j--) {
            d[i][j]=++cnt;
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%2d ", d[i][j]);
        } puts("");
    }

    return 0;
}

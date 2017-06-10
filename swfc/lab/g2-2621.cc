#include <iostream>
#include <algorithm>
using namespace std;
int v[251],d[251][251];
int main() {
    int n; scanf("%d",&n);
    int mx=0;
    for(int i=0; i<n; i++) {
        int x; scanf("%d",&x);
        d[i][i]=x;
        mx = max(mx,x);
    }
    for(int len=1; len<n; len++) {
        for(int s=0; s+len<n; s++) {
            int e=s+len;
            for(int k=s; k+1<=e; k++) {
                if(d[s][k]==d[k+1][e] && d[s][k]) {
                    d[s][e] = max(d[s][e],d[s][k]+1);
                }
            }
            mx = max(mx,d[s][e]);
        }
    }
    printf("%d",mx);
    return 0;
}

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const long long MOD = 1e9+7LL;
long long d[2][5001];
int h[10001];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin>>n;
    for(int i=1; i<=n; i++) cin >> h[i];

    if(n==1&&(h[1]==-1||h[1]==0)) {
        puts("1"); return 0;
    } else if(h[1]>0 || h[n]>0) {
        puts("0"); return 0;
    } else h[1]=h[n]=0;

    d[1][0]=1LL;
    for(int i=2,t=1; i<=n; i++,t^=1) {
        int lim = min(i,n-i+1)-1;
        for(int j=0; j<=lim; j++) {
            if(h[i]==-1 || h[i]==j) {
                d[t^1][j] = d[t][j]+d[t][j+1];
                if(j!=0) d[t^1][j]+=d[t][j-1];
                if(d[t^1][j]>=MOD) d[t^1][j]%=MOD;
            } else d[t^1][j]=0LL;
        }
    }

    cout << d[n&1][0] <<"\n";
    return 0;
}

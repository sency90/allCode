#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int v[21], d[21][21][21], m;
int f(int s, int l, int r) {
    if(s==m) return 0;
    int &ret = d[s][l][r];
    if(ret!=-1) return ret;
    ret = inf;
    if(v[s+1]<r) ret = f(s+1,v[s+1],r)+abs(l-v[s+1]);
    if(v[s+1]>l) ret = min(ret, f(s+1,l,v[s+1])+abs(r-v[s+1]));
    return ret;
}
int main() {
    int n,l,r;
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>l>>r>>m;
    if(l>r) swap(l,r);
    memset(d, -1, sizeof(d));
    for(int i=1; i<=m; i++) cin >> v[i];
    cout << f(0,l,r) << "\n";
    return 0;
}

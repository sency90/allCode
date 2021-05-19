#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
vector<int> v[100001];
int ss[100001], ee[100001];
ll bit[100001];
int cnt=0;
void add(int i, int by) {
    for(;i<=cnt;i+=i&-i) bit[i]+=by;
}
ll query(int i) {
    ll ret=0ll;
    for(;i;i-=i&-i) ret+=bit[i];
    return ret;
}
void dfs(int x) {
    ss[x]=++cnt;
    for(int y: v[x]) dfs(y);
    ee[x]=cnt;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        int x; cin >> x;
        if(x>0) v[x].emplace_back(i);
    }
    dfs(1);
    for(int i=0; i<m; i++) {
        int t,x,w;
        cin >>t>>x;
        if(t==1) {
            cin >> w;
            add(ss[x],w);
        } else cout << query(ee[x])-query(ss[x]-1) << "\n";
    }
    return 0;
}

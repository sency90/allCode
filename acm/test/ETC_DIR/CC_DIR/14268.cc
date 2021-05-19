#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
vector<int> v[100001];
int ss[100001], ee[100001], tree[100001];
int idx=0;
void dfs(int x) {
    ss[x]=++idx;
    for(int y: v[x]) dfs(y);
    ee[x]=idx;
}
int s,e;
void update(int at, int by) {
    for(;at<=e; at+=at&-at) tree[at]+=by;
}
int query(int at) {
    int ret=0; for(;at;at-=at&-at) ret+=tree[at];
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m; cin >>n>>m;
    for(int i=1; i<=n; i++) {
        int x; cin>>x;
        if(x<0) v[0].push_back(i);
        else v[x].push_back(i);
    }
    dfs(1);
    s=1; e=idx;
    for(int i=0; i<m; i++) {
        int t,at,by;
        cin >>t>>at;
        if(t==1) {
            cin>>by;
            update(ss[at],by);
            update(ee[at]+1,-by);
        } else cout << query(ss[at]) <<"\n";
    }
    return 0;
}

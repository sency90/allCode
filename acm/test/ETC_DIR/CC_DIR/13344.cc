#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
int p[50001];
int ind[50001];
queue<int> q;
vector<pii> gt;
vector<int> v[50001], g;

void init(int n) {
    for(int i=0; i<n; i++) {
        p[i] = i;
    }
}
int find(int x) {
    if(x==p[x]) return x;
    return p[x] = find(p[x]);
}
bool uni(int x, int y) {
    x=find(x); y=find(y);
    if(x==y) return true;
    if(y < x) { swap(x,y); }

    p[y] = x;
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m; cin >> n >> m;
    init(n);
    int x,y; string s;
    for(int i=0; i<m; i++) {
        cin >> x >> s >> y;
        if(s[0]=='=') uni(x,y);
        else gt.emplace_back(x,y);
    }

    for(int i=0; i<(int)gt.size(); i++) {
        int x=gt[i].first, y=gt[i].second;
        x = find(x); y = find(y);
        g.push_back(x); g.push_back(y);
        v[y].push_back(x); //y->x
        ind[x]++;
    }

    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for(int i=0; i<(int)g.size(); i++) {
        if(ind[g[i]]==0) q.push(g[i]);
    }

    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int y: v[x]) {
            if(--ind[y]==0) q.push(y);
        }
    }

    for(int i=0; i<(int)g.size(); i++) {
        if(ind[g[i]]!=0) return 0&puts("inconsistent");
    }

    puts("consistent");
    return 0;
}

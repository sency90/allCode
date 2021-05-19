#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
struct Edge{
    int e, w;
    Edge () {}
    Edge(int ee, int ww) {
        e=ee; w=ww;
    }
};
int d[100001], p[100001][17], lmn[100001][17], lmx[100001][17];
Edge parent[100001];
vector<Edge> v[100001];
queue<Edge> q;
bool chk[100001];
int main() {
    memset(chk, false, sizeof(chk));
    //memset(p, 0, sizeof(p));
    int n, k, s, e, w;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d %d %d", &s, &e, &w);
        v[s].push_back(Edge(e,w));
        v[e].push_back(Edge(s,w));
    }
    int depth = 1;
    chk[1] = true;
    d[1] = 0;
    q.push(Edge(1,0));
    while(!q.empty()) {
        int sz = q.size();
        for(int i=0; i<sz; i++) {
            Edge ed = q.front(); q.pop();
            for(int j=0; j<v[ed.e].size(); j++) {
                if(chk[v[ed.e][j].e]) continue;
                chk[v[ed.e][j].e] = true;
                d[v[ed.e][j].e] = depth;
                parent[v[ed.e][j].e] = Edge(ed.e, v[ed.e][j].w);
                q.push(v[ed.e][j]);
            }
        }depth++;
    }
    memset(p, 0, sizeof(p));
    for(int i=1; i<=n; i++) {
        p[i][0] = parent[i].e;
        lmn[i][0] = parent[i].w;
        lmx[i][0] = parent[i].w;
    }
    for(int j=1; (1<<j)<n; j++) {
        for(int i=1; i<=n; i++) {
            if(p[i][j-1]==0) continue;
            p[i][j] = p[p[i][j-1]][j-1];
            lmn[i][j] = lmn[i][j-1];
            lmx[i][j] = lmx[i][j-1];
            if(p[p[i][j-1]][j-1]==0) continue;
            if(lmn[i][j] > lmn[p[i][j-1]][j-1]) lmn[i][j] = lmn[p[i][j-1]][j-1];
            if(lmx[i][j] < lmx[p[i][j-1]][j-1]) lmx[i][j] = lmx[p[i][j-1]][j-1];
        }
    }

    scanf("%d", &k);
    for(int i=0; i<k; i++) {
        scanf("%d %d", &s, &e);
        if(d[s] < d[e]) swap(s,e);
        int mn = 10000001;
        int mx = 0;
        int k;
        while(d[s]!=d[e]) {
            for(k=1; (1<<k)<=d[s]-d[e]; k++);
            k--;
            if(lmn[s][k]!=0 && mn > lmn[s][k]) mn = lmn[s][k];
            if(mx < lmx[s][k]) mx = lmx[s][k];
            s=p[s][k];
        }
        if(s==e) {
            printf("%d %d\n", mn, mx);
            continue;
        }

        do{ for(k=0; (1<<k)<d[s]; k++) {
                if(p[s][k]==p[e][k]) break;
                if(lmn[s][k]!=0 && mn > lmn[s][k]) mn = lmn[s][k];
                if(lmn[e][k]!=0 && mn > lmn[e][k]) mn = lmn[e][k];
                if(mx < lmx[s][k]) mx = lmx[s][k];
                if(mx < lmx[e][k]) mx = lmx[e][k];
                s = p[s][k];
                e = p[e][k];
            }
        }while(k!=0);
        if(lmn[s][k]!=0 && mn > lmn[s][k]) mn = lmn[s][k];
        if(lmn[e][k]!=0 && mn > lmn[e][k]) mn = lmn[e][k];
        if(mx < lmx[s][k]) mx = lmx[s][k];
        if(mx < lmx[e][k]) mx = lmx[e][k];

        printf("%d %d\n", mn, mx);
    }
    return 0;
}

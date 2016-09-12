#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> v[53];
int level[53], p[53], c[53][53], f[53][53];
bool chk[53];
int ABS(int x) { return x<0?-x:x; }
bool buildLevelGraph(int src, int sink) {
    queue<int> q;
    memset(level, 0, sizeof(level));
    q.push(src); level[src]=1;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int i=0; i<v[x].size(); i++) {
            int y = v[x][i];
            if((c[x][y]-f[x][y] > 0 || f[y][x]>0) && level[y]==0) {
                level[y] = level[x]+1;
                q.push(y);
            }
        }
    }
    return level[sink]!=0;
}
int blockingFlow(int src, int sink) {
    int ret = 0;
    memset(chk, false, sizeof(chk));
    stack<int> s; s.push(src);
    while(!s.empty()) {
        int x = s.top();
        if(x != sink) {
            for(int i=0; i<v[x].size() && s.top()==x; i++) {
                int y = v[x][i];
                if(chk[y] || level[y]!=level[x]+1) continue;
                if(c[x][y]-f[x][y] > 0) s.push(y), p[y]=x;
                else if(f[y][x] > 0) s.push(y), p[y]=-x;
            }
            if(s.top() == x) s.pop(), chk[x]=true;
        } else {
            int flow = 1e9, bottleneck;
            for(int i=sink; i!=src; i=ABS(p[i])) {
                flow = min(flow, (p[i]>0)? c[p[i]][i]-f[p[i]][i] : f[i][-p[i]]);
            }
            for(int i=sink; i!=src; i=ABS(p[i])) {
                if(p[i]>0) {
                    f[p[i]][i] += flow;
                    if(c[p[i]][i]-f[p[i]][i] == 0) bottleneck = p[i];
                } else {
                    f[i][-p[i]] -= flow;
                    if(f[i][-p[i]] == 0) bottleneck = -p[i];
                }
            }

            while(!s.empty() && s.top()!=bottleneck) s.pop();
            ret += flow;
        }
    }
    return ret;
}
int Dinic(int src, int sink) {
    int ret = 0;
    while(buildLevelGraph(src, sink)) ret += blockingFlow(src, sink);
    return ret;
}

int chg(char x) {
    if(isupper(x)) return x-'A'+26;
    else return x-'a';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,f,s,e;
    char ss,ee;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >>ss>>ee>>f;
        s=chg(ss); e=chg(ee);
        if(!c[s][e] && !c[e][s]) {
            v[s].push_back(e);
            v[e].push_back(s);
        }
        c[s][e] += f;
    }

    int src = chg('A'), sink = chg('Z');
    printf("%d", Dinic(src, sink));
    return 0;
}

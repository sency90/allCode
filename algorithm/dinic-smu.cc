#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
struct edge{int to, cap, rev; };
vector<edge> G[100];
int level[100];
int iter[100];
void addEdge(int from, int to, int cp){
    G[from].push_back(edge{to, cp, (int)G[to].size()});
    G[to].push_back(edge{from, 0, (int)G[from].size()-1});
}
void bfs(int s){
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[s]=0;
    q.push(s);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int i=0; i<G[v].size(); i++){
            edge &e=G[v][i];
            if(e.cap>0  &&  level[e.to]<0){
                level[e.to]=level[v]+1;
                q.push(e.to);
            }
        }
    }
}
int dfs(int v, int t, int f){
    if(v == t)return f;
    for(int &i=iter[v]; i<G[v].size(); i++){
        edge &e=G[v][i];
        if(e.cap>0  && level[v]<level[e.to]){
            int d=dfs(e.to, t, min(f, e.cap));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int maxFlow(int s, int t){
    int flow=0;
    while(true){
        bfs(s);
        if(level[t]<0)return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f=dfs(s, t, 1e9))>0){
            flow += f;
        }
    }
}
int main(){

    return 0;
}

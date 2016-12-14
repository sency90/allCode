#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
vector<int> v[10001];
vector<int> pressGraph[10001];
bool visited[10001];
int SCC[10001];
int sccIdx;
int compCnt[10001];
int rel[10001];
 
int min(int a, int b){return a<b?a:b;}
 
stack<int> s;
int idx[10001];
int curIdx;
int strongConnect(int a){
    s.push(a);
    idx[a] = ++curIdx;
    int lowlink = idx[a];
 
    int size = v[a].size();
    for(int i = 0 ; i < size; i++){
        int b = v[a][i];
        if(idx[b] == 0) lowlink = min(lowlink, strongConnect(b));
        else if(!SCC[b]) lowlink = min(lowlink, idx[b]);
    }
 
    if(lowlink == idx[a]){
        sccIdx++;
        while(true){
            int b = s.top();
            s.pop();
            compCnt[sccIdx]++;
            SCC[b] = sccIdx;
            if(b == a) break;
        }
    }
 
    return lowlink;
}
 
int cntUnderComp(int s){
    if(visited[s]) return 0;
    visited[s] = true;
    int ans = compCnt[s];
    int size = pressGraph[s].size();
    for(int i = 0 ; i < size ; i++){
        int next = pressGraph[s][i];
        ans += cntUnderComp(next);
    }
    return ans;
}
 
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
 
    // make graph using adjacency list
    for(int i = 0 ; i < M ; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[b].push_back(a);
    }
 
    // get scc
    for(int i = 1 ; i <= N ; i++){
        if(idx[i] == 0){
            strongConnect(i);
        }
    }
 
    // press directed acyclic graph(pressGraph) based on scc
    for(int i = 1 ; i <= N ; i++){
        int size = v[i].size();
        for(int j = 0 ; j < size ; j++){
            int w = v[i][j];
            if(SCC[i] != SCC[w]) pressGraph[SCC[i]].push_back(SCC[w]);
        }
    }
 
    // count child component on dag
    for(int i = 1 ; i <= sccIdx ; i++){
        memset(visited,0,sizeof(visited));
        rel[i] = cntUnderComp(i);
    }
 
    // get component which have the most child node
    int max = 0;
    for(int i = 1 ; i <= sccIdx ; i++){
        if(max < rel[i]) max = rel[i];
    }
 
    // print ans
    for(int i = 1; i <= N ; i++){
        if(rel[SCC[i]] == max){
            printf("%d ",i);
        }
    }
 
    return 0;
}
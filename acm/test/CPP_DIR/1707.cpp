#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;
char color[20001]; //CHECK:0, RED: 1, BLUE: 2
stack<int> s;
vector<int> v[20001];
bool isBGraph;
void dfs(int x, char prevColor) {
    color[x] = 3-prevColor;
    for(int i=0; i<v[x].size(); i++) {
        if(v[x][i]==x) continue;
        else if(color[v[x][i]] == 0) dfs(v[x][i], color[x]);
        else if(color[v[x][i]] == color[x]) {
            isBGraph = false;
            return;
        }
    }
}
int main() {
    int K, V, E, x, y;
    scanf("%d", &K);
    while(K--) {
        memset(color, 0, sizeof(color));
        for(int i=0; i<20001; i++) v[i].clear();
        isBGraph = true;
        scanf("%d %d", &V, &E);
        for(int i=0; i<E; i++) {
            scanf("%d %d", &x, &y);
            v[x].push_back(y);
            v[y].push_back(x);
        }

        for(int i=1; i<=V; i++) {
            if(!isBGraph) break;
            if(color[i] == 0) dfs(i, 1);
        }

        if(isBGraph) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

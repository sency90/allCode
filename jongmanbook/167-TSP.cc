#include <iostream>
#include <cstring>
using namespace std;
bool vis[11];
int n, v[11][11], mn=0x3f3f3f3f;
void visit(int start, int next, int cost) {
    vis[next] = true;
    bool finished = true;
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            finished = false;
            break;
        }
    }
    if(finished) {
        if(v[next][start]==0) return;
        if(cost+v[next][start] < mn) mn=cost+v[next][start];
        return;
    }

    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        if(v[next][i]==0) continue;
        if(cost+v[next][i]>mn) continue;
        visit(start,i,cost+v[next][i]);
        vis[i]=false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> v[i][j];
        }
    }

    visit(0,0,0);
    printf("%d\n", mn);
    return 0;
}

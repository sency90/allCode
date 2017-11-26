#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define N 100
using namespace std;
int err[N+1][N+1];
vector<int> v[N+1];
bool achk[N+1],bchk[N+1];
int a[N+1],b[N+1];
bool bipartite(int x) {
    if(achk[x]) return false;
    achk[x]=true;
    for(int y: v[x]) {
        if(b[y]<0 || bipartite(y)) {
            b[y]=x;
            return true;
        }
    }
    return false;
}
int main() {
    int n,m; scanf("%d%d", &n,&m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d",&err[i][j]);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(err[i][j]) v[i].push_back(j);
        }
    }

    int cnt=0;
    for(int i=0; i<n; i++) {
        memset(achk,false,sizeof(achk));
        if(bipartite(i)) cnt++;
    }

    printf("%d", cnt);
    return 0;
}

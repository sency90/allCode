#include <cstdio>
using namespace std;
int v[51][51], g[51][51];
int main() {
    int n,m; scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d",&v[i][j]);
        }
    }
    for(int i=0; i<n; i++) {
        int b = (v[i][0]-1)/m;
        for(int j=0; j<m; j++) {
            if((v[i][j]-1)/m != b) return 0&puts("0");
            else g[i][j]=(v[i][j]-1)%m;
        }
    }

    for(int j=0; j<m; j++) {
        for(int i=0; i+1<n; i++) {
            if(g[i][j]!=g[i+1][j]) return 0&puts("0");
        }
    }
    puts("1");
    return 0;
}

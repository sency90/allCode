#include <stdio.h>
#include <vector>
using namespace std;
int v[50][50], s[50];
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &v[i][j]);
            s[i] += v[i][j];
        }
    }
    int res = s[0];
    for(int i=1; i<n; i++) {
        res ^= s[i];
    }
    if(res) puts("august14");
    else puts("ainta");
    return 0;
}

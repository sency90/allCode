#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vx[10001], vy[10001];
int main() {
    int n, ans=0, x, y;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        vx[x].push_back(y);
        vy[y].push_back(x);
    }
    for(int i=0; i<=10000; i++) {
        sort(vx[i].begin(), vx[i].end());
        sort(vy[i].begin(), vy[i].end());
    }
    for(int i=0; i<=10000; i++) {
        for(int j=1; j<vx[i].size(); j+=2) {
            ans+=(vx[i][j]-vx[i][j-1]);
        }
        for(int j=1; j<vy[i].size(); j+=2) {
            ans+=(vy[i][j]-vy[i][j-1]);
        }
    }
    printf("%d", ans);
    return 0;
}


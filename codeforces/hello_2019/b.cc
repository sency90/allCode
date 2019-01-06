#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int v[16], n;
bool hasAns = false;
void dfs(int x, int sum) {
    if(x==n) {
        if(sum%360 == 0) hasAns = true;
        return;
    }
    if(!hasAns) dfs(x+1,sum+v[x]);
    if(!hasAns) dfs(x+1,sum-v[x]);
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    dfs(0,0);
    if(hasAns) puts("YES");
    else puts("NO");
    return 0;
}

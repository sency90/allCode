#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
const int inf = 0x3f3f3f3f;
map<int, int> mp;
int f(int n, int x) {
    //printf("(%d,%d)\n", n,x);
    if(x==0) return 0;
    if(n==x) return 1;
    else if(n>x) return inf;
    int ret = f(n+1, x-n*2)+2;
    if(ret >= inf) ret = f(n, x-n)+1;
    return ret;
}
int main() {
    int n; scanf("%d", &n);
    int x, y;
    for(int i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        if(mp.count(y-x) == 0) mp[y-x] = f(1, y-x);
        printf("%d\n", mp[y-x]);
    }
    return 0;
}



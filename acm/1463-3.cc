#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int ans[1000001];
bool chk[1000001]; //initialize with false;
int cnt=0;
int f(int x) {
    if(x==1) return 0;
    if(chk[x]) return ans[x];
    chk[x] = true;

    if(x%3==0) ans[x] = min(f(x-1),f(x/3))+1;
    else if(x%2==0) ans[x] = min(f(x-1),f(x/2))+1;
    else ans[x] = f(x-1)+1;

    return ans[x];
}
int main() {
    int n; scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}

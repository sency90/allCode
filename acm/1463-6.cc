#include <cstdio>
#include <algorithm> // for min
using namespace std;
const int inf = 0x3f3f3f3f;
int ans[1000001];
int f(int x) {
    if(ans[x]!=inf) return ans[x];

    //base case
    if(x==1) return 0;

    //f(x) = min(f(x/3), f(x/2), f(x-1)) + 1;
    int &ret = ans[x];
    if(x%3==0) ret = min(ret, f(x/3)+1);
    if(x%2==0) ret = min(ret, f(x/2)+1);
    ret = min(ret, f(x-1)+1);
    return ret;
}
int main() {
    for(int i=0; i<=1000000; i++) ans[i] = inf;
    int x; scanf("%d", &x);
    printf("%d", f(x));
    return 0;
}

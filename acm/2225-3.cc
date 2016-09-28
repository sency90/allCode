#include <cstdio>
using namespace std;
const int mod = 1e9;
int d[201][201];
int f(int n, int k) {
    if(k==1) return 1;
    int &ret = d[n][k];
    if(ret) return ret;
    for(int i=0; i<=n; i++) {
        ret += f(n-i,k-1);
        ret %= mod;
    }
    return ret;
}
int main() {
    int n, k;
    scanf("%d%d",&n,&k);
    printf("%d\n",f(n,k));
    return 0;
}

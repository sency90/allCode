#include <iostream>
#include <cstring>
using namespace std;
const int mod = 1e5+7;
int a[10001], b[10001];
int f(int);
int g(int x) {
    if(x==1) return 0;
    if(x==2) return 2;
    if(b[x]>=0) return b[x];
    else b[x]=0;
    return b[x] = (2*f(x-2)+g(x-1)) %mod;
}
int f(int x) {
    if(x==0) return 1;
    if(x==1) return 2;
    if(a[x]>=0) return a[x];
    else a[x]=0;
    return a[x] = (2*f(x-1)+f(x-2)+g(x)) %mod;
}
int main() {
    memset(a,-1,sizeof(a));
    memset(b,-1,sizeof(b));
    int n; scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}

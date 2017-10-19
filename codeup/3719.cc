#include <iostream>
#include <cstring>
using namespace std;
const int mod = 1e5+7;
int d[10001], d2[10001];
int f(int x);
int g(int x) {
    if(x==1) return 0;
    else if(x==2) return 2;
    int &ret = d2[x];
    if(ret>=0) return ret;
    else ret=0;
    ret = 2*f(x-2)+g(x-1);
    ret %= mod;
    return ret;
}
int f(int x) {
    if(x==0) return 1;
    else if(x==1) return 2;
    int &ret = d[x];
    if(ret>=0) return ret;
    else ret=0;
    ret = 2*f(x-1)+f(x-2)+g(x);
    ret %= mod;
    return ret;
}
int main() {
    memset(d,-1,sizeof(d));
    memset(d2,-1,sizeof(d2));
    int n; scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}

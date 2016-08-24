#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1000001];
int a[1000001], b[1000001];
int g(int);
int f(int x) {
    if(x==0) return 0;
    if(a[x]!=-1) return a[x];
    if(s[x]=='A') return a[x] = f(x-1);
    else return a[x] = min(f(x-1),g(x-1))+1;
}
int g(int x) {
    if(x==0) return 0;
    if(b[x]!=-1) return b[x];
    if(s[x]=='B') return b[x] = g(x-1);
    else return b[x] = min(f(x-1),g(x-1))+1;
}
int main() {
    int n;
    memset(a,-1,sizeof(a));
    memset(b,-1,sizeof(b));
    scanf("%d%s",&n, s+1);
    printf("%d", min(f(n),g(n)+1));
    return 0;
}

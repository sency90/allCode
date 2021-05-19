#include <stdio.h>
#include <cstring>
using namespace std;
const long long MOD = 1000000007;
long long d[51][51][51][51];
long long f(int s, int a, int b, int c) {
    if(a+b+c<s) return 0;
    if(s<0||a<0||b<0||c<0) return 0;
    if(s==0&&a==0&&b==0&&c==0) return 1LL;
    if(s==0) return 0;
    if(d[s][a][b][c]!=-1) return d[s][a][b][c];

    return d[s][a][b][c] = (f(s-1,a-1,b,c)+f(s-1,a,b-1,c)+f(s-1,a,b,c-1)+f(s-1,a-1,b-1,c)+f(s-1,a-1,b,c-1)+f(s-1,a,b-1,c-1)+f(s-1,a-1,b-1,c-1))%MOD;
}
int main() {
    int s, a,b,c;
    memset(d, -1, sizeof(d));
    scanf("%d%d%d%d",&s,&a,&b,&c);
    printf("%lld", f(s,a,b,c)%MOD);
    return 0;
}

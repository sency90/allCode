#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
ll mod = 1e9+7LL;
ll d[101][101][101];
ll f(int x, int l, int r) {
    if(l==1 && r==1) return (x==1);
    else if(l<1 || r<1 || l+r>x+1) return 0;
    ll &ret = d[x][l][r];
    if(ret) return ret;
    return ret = ((x-2)*f(x-1,l,r)+f(x-1,l-1,r)+f(x-1,l,r-1))%mod;
}
int main() {
    freopen("in.txt", "r", stdin);
    int n,l,r,idx=0;
    char title[10];
    while(~scanf("%d%d%d",&n,&l,&r)) {
        idx++;
        sprintf(title, "%d.in", idx);
        FILE *inf = fopen(title, "w");
        fprintf(inf, "%d %d %d",n,l,r);
        fclose(inf);

        sprintf(title, "%d.out", idx);
        FILE *outf = fopen(title, "w");
        memset(d,0,sizeof(d));
        fprintf(outf, "%lld", f(n,l,r));
        fclose(outf);
    }
    return 0;
}

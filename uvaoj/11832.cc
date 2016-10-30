#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=36000, dmaxn=72000;
vector<int> v;
int neg[41][72021], pos[41][72021];
bool ispos[41], isneg[41];
int N,M;
bool f(int x, int sum) {
    if(x==0) return (M==sum);
    int &n=neg[x][sum], &p=pos[x][sum];
    if(n!=-1&&p!=-1) return n|p;
    else n=p=0;

    if(sum-v[x]<=dmaxn) n|=f(x-1,sum-v[x]);
    if(sum+v[x]<=dmaxn) p|=f(x-1,sum+v[x]);
    isneg[x]|=n; ispos[x]|=p;
    return n|p;
}
int main() {
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
        if((n|m)==0) return 0;
        v.clear(); v.resize(n+1,0);
        memset(neg,-1,sizeof(neg));
        memset(pos,-1,sizeof(pos));
        memset(ispos,false,sizeof(ispos));
        memset(isneg,false,sizeof(isneg));
        N=n; M=m+maxn;
        for(int i=1; i<=n; i++) {
            scanf("%d", &v[i]);
        }
        if(!f(n,maxn)) puts("*");
        else {
            for(int i=1; i<=n; i++) {
                if(ispos[i]&&isneg[i]) putchar('?');
                else printf("%c",(ispos[i])?'+':'-');
            } puts("");
        }
    }
    return 0;
}

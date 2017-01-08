#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll d[21][21][20001], po[21][21];
ll f(int x, int y, int p) {
    if(p<0) return f(x,y,0);
    ll &ret = d[x][y][p];
    if(ret>=0LL) return ret;
    else ret=0LL;
    if(x==0) return ret=(p==0);

    for(int i=1; i<=y; i++) ret+=f(x-1,y,p-i);
    return ret;
}
ll spow(int y, int x) {
    ll &ret = po[y][x];
    if(ret) return ret;
    if(x==0) return ret=1LL;

    ret = spow(y,x>>1);
    if(x&1) return ret=ret*ret*y;
    else return ret*=ret;
}
double div(double ans, int x, double y) {
    for(int i=0; i<x; i++) ans/=y;
    return ans;
}
int main() {
    memset(d,-1,sizeof(d));
    memset(po,0,sizeof(po));
    int tc; scanf("%d", &tc);
    for(int t=1; t<=tc; t++) {
        int h,s,x,y,z;
        scanf("%d%d",&h,&s);
        double ans=0.0;
        for(int i=0; i<s; i++) {
            char ch;
            scanf("%dd%d%c",&x,&y,&ch);
            if(ch==' '||ch=='\n'||ch=='\r') z=0;
            else {
                scanf("%d",&z);
                if(ch=='-') z*=-1;
            }
            ans = max(ans, double(f(x,y,h-z))/spow(y,x));
        }
        printf("Case #%d: %.6lf\n",t,ans);
    }
}

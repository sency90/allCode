#include <iostream>
#include <algorithm>
using namespace std;
int s[50001], d[50001][3];
bool chk[50001][3];
int lim;
int f(int x,int y) {
    if(x==0||y==0) return 0;
    int &ret = d[x][y];
    if(chk[x][y]) return ret;
    chk[x][y]=true;

    ret = max(ret,f(x-1,y));
    if(x-lim<0) ret = max(ret,f(0,y-1)+s[x]);
    else ret = max(ret,f(x-lim,y-1)+s[x]-s[x-lim]);
    return ret;
}
int main() {
    //freopen("input.txt","r",stdin);
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        int x;
        scanf("%d",&x);
        s[i]=s[i-1]+x;
    }
    scanf("%d",&lim);
    printf("%d\n",f(n,3));
    return 0;
}

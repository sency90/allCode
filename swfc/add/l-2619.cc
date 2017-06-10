#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int cow[5001],um[100001],p[100001];
const int inf = 0x3f3f3f3f;
int d[5001];
bool chk[5001];
int f(int x) {
    if(x<=0) return 0;
    if(chk[x]) return d[x];
    chk[x]=true;

    for(int i=0; x-i>=1; i++) {
        d[x] = min(d[x],f(x-i-1)+um[cow[x]-cow[x-i]]);
    }
    return d[x];
}
int main() {
    //freopen("input.txt","r",stdin);
    memset(d,0x3f,sizeof(d));
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        scanf("%d",&cow[i]);
    }
    sort(cow,cow+n+1);
    for(int i=1; i<=n; i++) {
        p[cow[i]]=cow[i-1];
    }
    for(int i=0; i<m; i++) {
        scanf("%d",&um[i]);
    }
    for(int i=m-2; i>=0; i--) {
        um[i]=min(um[i],um[i+1]);
    }
    printf("%d",f(n));
    return 0;
}

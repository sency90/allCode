#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int sero[101];
int main() {
    int n,m,s,e,del,draw;
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&s,&e,&del,&draw);
    for(int i=1; i<=n; i++) {
        if(i==s) sero[i]=0;
        else sero[i]=abs(i-s)*draw;
    }
    int p,c;
    for(int i=0; i<m; i++) {
        scanf("%d", &p);
        int tmp=sero[p];
        sero[p]=min({sero[p+1],sero[p]+del,sero[p]+draw});
        sero[p+1]=min({tmp,sero[p+1]+del,sero[p+1]+draw});
        for(int j=1;j<=n;j++) {
            if(j==p||j==p+1) continue;
            if(j-p>0) c=p+1;
            else c=p;
            int dist = abs(j-c)*draw;
            sero[j]=min(sero[j],sero[c]+dist);
        }
    }
    printf("%d\n",sero[e]);
    return 0;
}

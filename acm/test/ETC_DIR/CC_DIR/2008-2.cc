#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main() {
    int n,m,s,e,x,y,p,c,tmp,d[101];
    scanf("%d%d%d%d%d%d",&n,&m,&s,&e,&x,&y);
    for(int i=1;i<=n;i++) d[i]=abs(i-s)*y;
    for(int i=0;i<m;i++) {
        scanf("%d", &p);
        tmp=d[p];
        d[p]=min({d[p+1],d[p]+x,d[p]+y});
        d[p+1]=min({tmp,d[p+1]+x,d[p+1]+y});
        for(int j=1;j<=n;j++) {
            c=p+((j-p)>0);
            d[j]=min(d[j],d[c]+abs(j-c)*y);
        }
    }
    printf("%d\n",d[e]);
    return 0;
}

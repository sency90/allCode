#include <stdio.h>
int main() {
    int x1,x2,y1,y2,r1,r2,t,d,l,b,ans;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d%d%d%d",&x1,&y1,&r1,&x2,&y2,&r2);
        d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        l = (r1-r2)*(r1-r2);
        b = (r1+r2)*(r1+r2);
        if(d==0 && (r1==r2)) ans=-1;
        else if(d<l || d>b) ans=0;
        else if(d==l || d==b) ans=1;
        else ans=2;
        printf("%d\n",ans);
    }
}

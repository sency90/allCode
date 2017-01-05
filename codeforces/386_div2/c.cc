#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
int main() {
    int n,x1,x2,t1,t2,p,d;
    scanf("%d%d%d%d%d%d%d",&n,&x1,&x2,&t1,&t2,&p,&d);
    int human=abs(x2-x1)*t2,s=0,ans=0;
    if(d>0) {
        if(p<=x1 && x1<x2) s=x2-p;
        else if(x1<=p && p<=x2) s=2*(n-p)+2*p+(x2-p);
        else if(x1<x2 && x2<=p) s=2*(n-p)+p+x2;
        else if(p<=x2 && x2<x1) s=(n-p)+(n-x2);
        else if(x2<=p && p<=x1) s=2*(n-p)+p-x2;
        else if(x2<x1 && x1<=p) s=n-p+(n-x2);
        ans = min(s*t1, human);
    } else {
        if(p<=x1 && x1<x2) s=p+x2;
        else if(x1<=p && p<=x2) s=p+x2;
        else if(x1<x2 && x2<=p) s=p+x2;
        else if(p<=x2 && x2<x1) s=p+n+(n-x2);
        else if(x2<=p && p<x1) s=p+n+(n-x2);
        else if(x2<x1 && x1<=p) s=p-x2;
        ans = min(s*t1, human);
    }
    printf("%d", ans);
    return 0;
}

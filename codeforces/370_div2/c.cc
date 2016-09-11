#include <cstdio>
#include <algorithm>
using namespace std;
int MIN(const int *a) {
    int x = min({a[0],a[1],a[2]});
    for(int i=0; i<3; i++) {
        if(a[i]==x) return i;
    }
    return 0;
}
int main() {
    int x,y;
    scanf("%d%d",&x,&y);
    int a[3],ridx[2], idx;
    a[0]=a[1]=a[2]=y;
    int cnt=0;

    bool hasAns=true;
    while(true) {
        hasAns=true;
        idx = MIN(a);
        if(idx==2) {
            ridx[0]=0;
            ridx[1]=1;
        } else if(idx==1) {
            ridx[0]=0;
            ridx[1]=2;
        } else {
            ridx[0]=1;
            ridx[1]=2;
        }

        if(x<a[ridx[0]]+a[ridx[1]]) a[idx]=x;
        else a[idx]=a[ridx[0]]+a[ridx[1]]-1;
        for(int i=0; i<3; i++) {
            if(a[i]!=x) hasAns=false;
        }
        cnt++;
        if(hasAns) break;
    }
    printf("%d", cnt);
    return 0;
}

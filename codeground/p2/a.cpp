#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct Rectangle{
    long long dx,dy,x1,y1,x2,y2;
    Rectangle() {}
    Rectangle(int x, int y, int u, int v) {
        dx=u-x; dy=v-y; x1=x; y1=y; x2=u; y2=v;
    }
    bool operator<(const Rectangle& rhs) const {
        return dx*dy < rhs.dx*rhs.dy;
    }
    bool operator>(const Rectangle& rhs) const {
        if(x1<rhs.x1 && rhs.x2<x2 && y1<rhs.y1 && rhs.y2<y2) return true;
        else return false;
    }
};
vector<Rectangle> v;
long long d[5020];
bool chk[5020];
long long f(int r) {
    if(r==0) return 1;
    if(chk[r]) return d[r];
    chk[r] = true;
    long long tmp;
    for(int i=0; i<r; i++) {
        if(v[r] > v[i]) {
            tmp = f(i)+1;
            if(d[r]<tmp) d[r]=tmp;
        }
    }
    //if(d[r]==-1) d[r]=1;
    return d[r];
}
int main() {
    int t,n,m,k;
    long long x1,y1,x2,y2;
    setbuf(stdout, NULL);
    scanf("%d", &t);
    for(int z=1; z<=t; z++) {
        v.clear();
        memset(d, 0, sizeof(d));
        memset(chk, false, sizeof(chk));
        printf("Case #%d\n", z);
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0; i<k; i++) {
            scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
            v.push_back(Rectangle(x1,y1,x2,y2));
        }
        sort(v.begin(), v.end());
        long long tmp = f(k-1);
        if(tmp == 0) puts("1");
        printf("%lld\n", tmp);
    }
    return 0;
}

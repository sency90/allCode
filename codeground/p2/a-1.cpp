#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Rectangle{
    long long dx,dy,x1,y1,x2,y2;
    Rectangle() {}
    Rectangle(int x, int y, int u, int v) {
        x1=x; y1=y; x2=u; y2=v; dx=x-u; dy=y-v;
    }
    bool operator<(const Rectangle& rhs) const{
        return dx*dy < rhs.dx*rhs.dy;
    }
    //if A includes B
    bool includes(const Rectangle& rhs) const {
        if(x1<rhs.x1 && y1<rhs.y1 && rhs.x2<x2 && rhs.y2<y2) return true;
        else return false;
    }
};
vector<Rectangle> v;
long long d[5010];
bool chk[5010];


long long f(int r) {
    if(r==0) return 1LL;
    if(chk[r]) return d[r];
    chk[r] = true;
    long long tmp;
    for(int i=0; i<r; i++) {
        if(v[r].includes(v[i])) {
            tmp = f(i)+1;
            if(tmp > d[r]) d[r]=tmp;
        }
    }
    return d[r];
}

int main() {
    int testCase, n,m,k;
    long long x1,y1,x2,y2;
    scanf("%d", &testCase);
    setbuf(stdout, NULL);
    for(int z=1; z<=testCase; z++) {
        v.clear();
        memset(chk, false, sizeof(chk));
        printf("Case #%d\n", z);
        scanf("%d%d%d", &n,&m,&k);
        for(int i=0; i<k; i++) {
            d[i]=1LL;
        }
        for(int i=0; i<k; i++) {
            scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
            v.push_back(Rectangle(x1,y1,x2,y2));
        }
        sort(v.begin(), v.end());
        printf("%lld\n", f(k-1));
    }
    return 0;
}

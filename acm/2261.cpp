#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;
struct Coord{
    int x, y;
    bool operator<(const Coord& rhs) const {
        if(x == rhs.x) return y < rhs.y;
        else return x < rhs.x;
    }
    bool operator==(const Coord& rhs) const {
        if(x==rhs.x && y==rhs.y) return true;
        else return false;
    }
}co[100001];

int spow(Coord& cs, Coord& ce) {
    if(cs == ce) return 0;
    return (ce.x-cs.x)*(ce.x-cs.x)+(ce.y-cs.y)*(ce.y-cs.y);
}
int solve(int s, int e) {
    if(s==e) return 0LL;
    if(s+1==e) {
        return spow(co[e], co[s]);
    }
    int mid = (s+e)/2;
    int t, d = spow(co[e], co[s]);
    if(s!=mid)
        if(d > (t=solve(s, mid))) d=t;

    if(e!=mid+1)
        if(d > (t=solve(mid+1, e))) d=t;

    int i, j;
    for(i=mid; i>=s; i--) {
        for(j=mid+1; j<=e; j++) {
            t = co[j].x-co[i].x;
            if(t*t >= d) {
                break;
            } else {
                t = spow(co[j],co[i]);
                if(d > t) d=t;
            }
        }
        if(j == mid+1) break;
    }
    return d;
}
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &co[i].x, &co[i].y);
    }
    sort(co, co+n);
    printf("%d", solve(0, n-1));
    return 0;
}

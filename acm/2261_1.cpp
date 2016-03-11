#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;
struct Coord{
    int x, y;

    bool operator<(const Coord& rhs) const {
        if(rhs.x == x) {
            if(y < rhs.y) return true;
        } else if(x < rhs.x) return true;
        return false;
    }
    bool operator==(const Coord& rhs) const {
        if(rhs.x == x && rhs.y == y) return true;
        else return false;
    }
}co[100000];
long long spow(Coord& s, Coord& e) {
    if(s==e) return 0LL;
    return (long long)(e.x-s.x)*(e.x-s.x) + (long long)(e.y-s.y)*(e.y-s.y);

}
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &co[i].x, &co[i].y);
    }
    long long min = LONG_MAX, d;
    sort(co, co+n);
    for(int i=0; i<n-1; i++) {
        d = spow(co[i], co[i+1]);
        if(min > d) min = d;
    }
    printf("%lld", min);
    return 0;
}

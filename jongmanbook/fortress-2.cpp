#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
struct Castle{
    int x, y, r;
    Castle(){} Castle(int x, int y, int r) : x(x),y(y),r(r) {}
    bool operator<(const Castle &rhs) const {
        return r < rhs.r;
    }
}v[100];
int dist[100];
int main() {
    int tc, n, x,y,r, mx;
    scanf("%d", &tc);
    while(tc--) {
        mx=0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d%d%d",&x,&y,&r);
            v[i] = Castle(x,y,r);
        }
        sort(v, v+n);
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                x=v[i].x-v[j].x; y=v[i].y-v[j].y; r=v[j].r;
                if(x*x+y*y<=r*r) {
                    mx = max(mx, dist[j]+dist[i]+1);
                    dist[j] = max(dist[j], dist[i]+1);
                    break;
                }
            }
        }
        printf("%d\n", mx);
        memset(dist, 0, sizeof(dist));
    }
    return 0;
}

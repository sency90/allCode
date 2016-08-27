#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int cost[] = {0,1,1,1,2,2,2,1,1,1};
int disk[100], dest[100], d[100][10][10];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%1d", &disk[i]);
    }
    for(int i=0; i<n; i++) {
        scanf("%1d", &dest[i]);
    }
    memset(d, 0x3f, sizeof(d));
    d[0][0][0] = 0;
    const int inf = 0x3f3f3f3f;
    int ans = inf;
    for(int x=0; x<n; x++) {
        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                int &cur = d[x][i][j];
                if(cur == inf) continue;
                for(int two=0; two<10; two++) {
                    for(int three=0; three<10; three++) {
                        int one = ((disk[x]+i+two+three) - dest[x] +10)%10;
                        int tc = cur + cost[one] + cost[two] + cost[three];
                        int &next = d[x+1][(j+two+three)%10][three];
                        if(next > tc) {
                            next = tc;
                            if(x==n-1) {
                                ans = min(ans, next);
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}

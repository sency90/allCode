#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int d[100001][18];
int main() {
    int n, m, a, b, t;
    scanf("%d%d",&n,&m);
    memset(d, 0x3f, sizeof(d));
    for(int i=0; i<n; i++) {
        scanf("%d", &d[i][0]);
    }

    for(int j=1; (1<<j) < n; j++) {
        for(int i=0; i<n; i++) {
            t = 1<<(j-1);
            if(i+t >= n) d[i][j] = d[i][j-1]; //이 부분에서 대입하지 않고 break해줘도 상관 없음.
            else d[i][j] = min(d[i][j-1], d[i+t][j-1]);
        }
    }
    int mn, k;
    for(int i=0; i<m; i++) {
        scanf("%d%d",&a,&b);
        a--; b--;
        mn = 0x3f3f3f3f;
        if(a>b) swap(a,b);
        while(a!=b) {
            for(k=1; a+(1<<k) <= b; k++);
            k--;

            if(mn > d[a][k]) mn = d[a][k];
            a += (1<<k);
        }
        if(mn > d[a][0]) mn = d[a][0];
        printf("%d\n", mn);
    }
    return 0;
}

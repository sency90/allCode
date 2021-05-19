#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int v[100001];
int mx[370], mn[370];
int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    memset(mn, 0x3f, sizeof(mx));

    int x=sqrt(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
        mx[i/x] = max(mx[i/x], v[i]);
        mn[i/x] = min(mn[i/x], v[i]);
    }
    int s, e, ansmx, ansmn;
    for(int i=0; i<m; i++) {
        scanf("%d%d",&a,&b);
        a--; b--;
        if(a%x==0) s=a/x;
        else s=a/x+1;
        if(b%x==x-1) e=b/x;
        else e=b/x-1;

        int tmp = s*x;
        printf("%d %d\n", x, tmp);
        ansmx = 0;
        ansmn = 0x3f3f3f3f;
        for(int j=a; j<tmp; j++) {
            ansmx = max(ansmx, v[j]);
            ansmn = min(ansmn, v[j]);
            printf("v[j]: %d\n", v[j]);
        }
        printf("ansmx:%d ansmn:%d\n", ansmx, ansmn);
        printf("s: %d, e: %d\n", s, e);
        for(int j=s; j<=e; j++) {
            ansmx = max(ansmx, mx[j]);
            ansmn = min(ansmn, mn[j]);
            printf("v[j]: %d\n", v[j]);
        }
        printf("ansmx:%d ansmn:%d\n", ansmx, ansmn);
        for(int j=e*x; j<=b; j++) {
            ansmx = max(ansmx, v[j]);
            ansmn = min(ansmx, v[j]);
        }
        printf("%d %d\n", ansmn, ansmx);
    }
    return 0;
}

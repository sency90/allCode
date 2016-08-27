#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f;
int N,E;
int s[100], d[100][200001];
int f(int n, int e) {
    if(e*2 >= E) return 0;
    if(n == N) return inf;

    int &ret = d[n][e];
    if(ret!=-1) return ret;
    return ret = min(f(n+1,e), f(n+1, e+s[n])+s[n]);
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        scanf("%d%d",&N,&E);

        int sum=0;
        for(int i=0; i<N; i++) {
            scanf("%d", &s[i]);
            sum += s[i];
        }

        if(E>sum*2) puts("FULL");
        else if(E==0) puts("0");
        else {
            memset(d, -1, sizeof(d));
            printf("%d\n", f(0,0));
        }
    }
    return 0;
}

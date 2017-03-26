#include <cstdio>
#include <algorithm>
using namespace std;
int v[100001];
int main() {
    int n, table=0,d;
    scanf("%d", &n);
    int lim = n*2, mxtable=0;
    for(int i=0; i<lim; i++) {
        scanf("%d", &d);
        v[d]++;
        table++;
        if(v[d]==2) {
            v[d]=0;
            table-=2;
        }
        mxtable = max(table, mxtable);
    }
    printf("%d\n", mxtable);
    return 0;
}

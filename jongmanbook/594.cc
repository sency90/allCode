#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define SEMESTER 10
#define SUBJECTS 12
int subj[SEMESTER], pre[SUBJECTS], in, d[SEMESTER][1<<SUBJECTS];
int t,n,k,m,l,rcnt,ccnt;
const int inf = 0x3f3f3f3f;
void bitsPrint(int bits, int cnt) {
    if(bits==0) {
        for(int i=0; i<cnt; i++) putchar('0');
        return;
    }
    bitsPrint(bits/2, cnt-1);
    printf("%d", bits%2);
}
int bitsCount(int bits) {
    if(bits == 0) return 0;
    else return bits%2 + bitsCount(bits/2);
}
int f(int sem, int taken) {
    if(bitsCount(taken) >= k) return 0;
    else if(sem == m) return inf;
    if(d[sem][taken]!=-1) return d[sem][taken];

    int &ret = d[sem][taken], s;
    int canTake = (subj[sem] & (~taken));
    ret = inf;

    for(int i=0; i<n; i++) {
        s = (1<<i);
        if((s & canTake) && (pre[i] & ~taken)) canTake &= (~s);
    }
    for(int i=canTake; i; i=(i-1)&canTake) {
        if(bitsCount(i) > l) continue;
        ret = min(ret, f(sem+1, taken|i)+1);
    }
    ret = min(ret, f(sem+1, taken));
    return ret;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        memset(pre, 0, sizeof(pre));
        memset(subj, 0, sizeof(subj));
        memset(d, -1, sizeof(d));
        scanf("%d%d%d%d",&n,&k,&m,&l);
        for(int i=0; i<n; i++) {
            scanf("%d", &rcnt);
            for(int j=0; j<rcnt; j++) {
                scanf("%d", &in);
                pre[i]|=(1<<in);
            }
        }
        for(int i=0; i<m; i++) {
            scanf("%d", &ccnt);
            for(int j=0; j<ccnt; j++) {
                scanf("%d", &in);
                subj[i]|=(1<<in);
            }
        }

        int res = f(0,0);
        if(res >= inf) puts("IMPOSSIBLE");
        else printf("%d\n", res);
    }
    return 0;
}

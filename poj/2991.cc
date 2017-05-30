#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define r2 (r<<1)
#define m2 ((s+e)>>1)
using namespace std;
const int inf = 0x3f3f3f3f;
struct Seg{
    int s,e;
    vector<int> tree;
    Seg(int n):s(1) {
        for(e=0; (1<<e)<n; e++);
        tree.resize((1<<(e+1)),inf);
        e=1<<e;
    }
    int update(int r, int s, int e, int idx, int x) {
        if(e<idx || idx<s) return inf;
        else if(s==e) return tree[r]=x;
        else return tree[r] = min(update(r2,s,m2,idx,x),update(r2+1,m2+1,e,idx,x));
    }
    int query(int r, int s, int e, int qs, int qe) {
        if(qe<s || e<qs) return inf;
        else if(s<=qs && qe<=e) return tree[r];
        else return min(query(r2,s,m2,qs,qe),query(r2+1,m2+1,e,qs,qe));
    }
};
int main() {
    freopen("input.txt", "r", stdin);
    int n; scanf("%d", &n);
    Seg seg(n);
    for(int i=1; i<=n; i++) {
        int x; scanf("%d", &x);
        printf("%d ", x);
        seg.update(1,seg.s,seg.e,i,x); //이렇게 초기화 하는 수 밖에 없었나??
    } puts("");
    int s,e,m;
    scanf("%d", &m); printf("m: %d\n", m);
    for(int i=0; i<m; i++) {
        scanf("%d %d",&s,&e);
        printf("[%d,%d]: %d\n",s,e,seg.query(1,seg.s,seg.e,s,e));
    }
    return 0;
}

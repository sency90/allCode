#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
struct Seg{
    int s, e;
    vector<int> tree, lazy;
    Seg(int n):s(1) {
        for(e=0; (1<<e)<n; e++);
        tree.clear(); tree.resize((1<<(e+1)),0);
        lazy.clear(); lazy.resize((1<<(e+1)),0);
        e=1<<e;
    }
    int init(int r, int s, int e) {
        if(s==e) return tree[r]=v[s];
        else return tree[r]=init(r*2,s,(s+e)/2)^init(r*2+1,(s+e)/2+1,e);
    }
    void push_down(int r, int s, int e) {
        if(lazy[r]) {
            if(s==e) tree[r]^=lazy[r];
            else {
                lazy[r*2]^=lazy[r];
                lazy[r*2+1]^=lazy[r];
            }
            //이 segment tree는 full binary tree이기 때문에
            //xor 연산의 특성상 단말노드가 아니면 tree[r]을 업데이트 해줄 필요가 없었다.
            lazy[r]=0;
        }
    }
    int update(int r, int s, int e, int qs, int qe, int x) {
        if(qe<s||e<qs) {
            push_down(r,s,e);
            return tree[r];
        } else if(qs<=s&&e<=qe) {
            lazy[r]^=x;
            push_down(r,s,e);
            return tree[r];
        } else return tree[r]=update(r*2,s,(s+e)/2,qs,qe,x)^update(r*2+1,(s+e)/2+1,e,qs,qe,x);
    }
    int query(int r, int s, int e, int qs, int qe) {
        push_down(r,s,e);
        if(qe<s||e<qs) return 0;
        else if(qs<=s&&e<=qe) return tree[r];
        else return query(r*2,s,(s+e)/2,qs,qe)^query(r*2+1,(s+e)/2+1,e,qs,qe);
    }
};
int main() {
    int n; scanf("%d", &n);
    Seg seg(n);
    v.clear(); v.resize(seg.e+1,0);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    seg.init(1,seg.s,seg.e);
    int m,type; scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d",&type);
        int a,b,c;
        if(type==1) {
            scanf("%d%d%d",&a,&b,&c);
            seg.update(1,seg.s,seg.e,min(a,b)+1,max(a,b)+1,c);
        } else {
            scanf("%d%d",&a,&b);
            printf("%d\n", seg.query(1,seg.s,seg.e,min(a,b)+1,max(a,b)+1));
        }
    }
    return 0;
}

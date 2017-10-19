#include <stdio.h>
typedef long long ll;
inline void swap(ll &x,ll &y) { x^=y; y^=x; x^=y; }
inline int min(int x,int y) { return x<y?x:y; }
struct Heap{
    ll v[100001],sz=0;
    inline void push(int x) {
        v[++sz] = x;
        int p = sz>>1;
        if(p==0) return;
        else {
            int cur = sz;
            while(cur!=1) {
                if(v[p]>v[cur]) swap(v[cur],v[p]);
                else break;
                cur = p;
                p = cur>>1;
            }
        }
    }
    inline int top() { return v[1]; }
    inline void pop() {
        v[1]=v[sz--];
        int cur = 1;
        while(cur<=sz) {
            int l=cur*2,r=cur*2+1,tc=cur;
            ll t = v[cur];
            if(l<=sz && t>v[l]) t=v[l],tc=l;
            if(r<=sz && t>v[r]) t=v[r],tc=r;
            if(t!=v[cur]) swap(v[cur],v[tc]);
            else break;
            cur = tc;
        }
    }
    inline int size() { return sz; }
    inline bool empty() { return sz<=0; }
};
Heap h;
int main() {
    int n; scanf("%d",&n);
    for(int i=0; i<n; i++) {
        int x;
        scanf("%d",&x);
        h.push(x);
    }
    ll ans=0LL;
    while(h.size()>1) {
        ll x=h.top(); h.pop();
        ll y=h.top(); h.pop();
        ans+=x+y;
        h.push(x+y);
    }
    printf("%lld\n",ans);
    return 0;
}

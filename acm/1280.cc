#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define r2 (r<<1)
#define m2 ((s+e)>>1)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
vector<pii> tree;
struct Info{
    ll s; int c;
    Info():s(0LL),c(0){}
    Info(ll s, int c):s(s),c(c){}
    Info operator+(Info rhs) { return Info(s+rhs.s, c+rhs.c); }
    void print() {
        printf("sum: %lld, cnt: %d", s,c);
    }
};
struct Ret{
    Info l, r;
    Ret():l(Info()),r(Info()){} Ret(Info l, Info r):l(l),r(r){}
    Ret operator+(Ret rhs) { return Ret(l+rhs.l, r+rhs.r); }
    void print() {
        printf("LEFT => ");
        l.print();
        printf("\t RIGHT => ");
        r.print();
        puts("");
    }
};

struct Seg{
    int s,e;
    Info defau;
    vector<Info> info;
    vector<Ret> ret;
    Seg(int n):s(0),defau(0LL,0) {
        for(e=0; (1<<e)<n; e++);
        ret.clear(); ret.resize(1<<(e+1));
        info.clear(); info.resize(1<<(e+1));
        e=(1<<e)-1;
    }
    Ret query(int r, int s, int e, int i) {
        if(i<s) return Ret(defau,info[r]);
        else if(e<i) return Ret(info[r],defau);
        else if(s==e) {
            info[r] = Info(tree[i].first,1);
            return Ret(defau,defau);
        } else {
            Ret L=query(r2,s,m2,i), R=query(r2+1,m2+1,e,i);
            info[r]=info[r2]+info[r2+1];
            return L+R;
        }
    }
};
const ll mod = 1e9+7LL;
int idx[200000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        tree.push_back({x, i});
    }
    sort(tree.begin(), tree.end());
    //idx.resize(n);
    for(int i=0; i<n; i++) idx[tree[i].second]=i;
    Seg seg(n);
    seg.query(1,seg.s,seg.e,idx[0]);
    ll ans=1LL;
    for(int i=1; i<n; i++) {
        Ret ret = seg.query(1,seg.s,seg.e,idx[i]);
        //ret.print();
        ll x = tree[idx[i]].first;
        ans = ans*((x*ret.l.c - ret.l.s)%mod+(ret.r.s - x*ret.r.c)%mod)%mod;
        //ans = (ans*( tree[idx[i]].first*(ret.l.c-ret.r.c) + ret.r.s-ret.l.s)%mod)%mod;
    }
    printf("%lld\n", ans);
}

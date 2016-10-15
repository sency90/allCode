#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
#define se second
#define fi first
#define pb push_back
#define bk back()
#define ls (r<<1)
#define rs ((r<<1) | 1)
#define mid ((s+e)>>1)
#define INF (0x3f3f3f3f)
const int maxo = 1000000;
ll cov[maxo], tree[maxo];
int dic[maxo];
void update(int r, int qs, int qe, int x, int s, int e){
    if (qs>=e||qe<=s) return;
    if (qs<=s&&e<=qe){
        cov[r]+=x;
        if(cov[r]==0){
            if (e - s <= 1) tree[r] = 0;
            else tree[r] = tree[ls] + tree[rs];
        } else if (cov[r]==1) tree[r] = dic[e] - dic[s];
        return;
    }
    update(ls,qs,qe,x,s,mid);
    update(rs,qs,qe,x,mid,e);
    if (cov[r]==0) tree[r]=tree[r<<1]+tree[(r<<1)|1];
}
struct line{
    int a, b, h, v;
    line(int a = 0, int b = 0, int h = 0, int v = 0): a(a), b(b), h(h), v(v) {}
    bool operator < (const line &c)const{
        return h < c.h;
    }
}qs[maxo];
int n, dh;
int idx(int x){
    return lower_bound(dic, dic+dh, x) - dic;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
    freopen("xx.out", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 0, a, b, c, d; i < n; i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (a > c || b > d) swap(a, c), swap(b, d);
        qs[i] = line(a, c+1, b, 1);
        qs[i+n] = line(a, c+1, d+1, -1);
        dic[i] = a;
        dic[i+n] = c+1;
    }
    sort(dic, dic+n * 2);
    sort(qs, qs+n * 2);
    dh = unique(dic, dic+n * 2) - dic;
    ll ans = 0;
    ll lastlen = 0, lastpos = INF;
    for(int i = 0; i < n * 2; i++){
        ans += lastlen * (qs[i].h - lastpos);
        update(1, idx(qs[i].a), idx(qs[i].b), qs[i].v, 0, dh);
        lastlen = tree[1];
        lastpos = qs[i].h;
    }
    cout << ans << endl;
  return 0;
}

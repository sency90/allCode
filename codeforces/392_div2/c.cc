#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vvll;
typedef pair<ll,ll> pll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
vvll cnt(201, vector<ll>(201,0ll));
vvll rcnt(201, vector<ll>(201,0ll));
ll getser(int n, int m, int x, int y, vvll& cnt) {
    return cnt[x-1][y-1];
}
pll getmnmx(int n, int m, int x, int y, vvll& cnt) {
    ll mx=0, mn=inf;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            mx = max(mx, cnt[i][j]);
            mn = min(mn, cnt[i][j]);
        }
    }
    return pll(mn,mx);
}
ll count_forward(int n, int m, int x, int y, vvll& cnt, int s, ll lim) {
    for(int i=s; i<n; i++) {
        for(int j=0; j<m; j++) {
            cnt[i][j]++;
            lim--;
            if(lim==0ll) return -1;
        }
    }
    return (n-s)*m;
}
ll count_backward(int n, int m, int x, int y, vvll& cnt, ll lim) {
    for(int i=n-2; i>=0; i--) {
        for(int j=0; j<m; j++) {
            cnt[i][j]++;
            lim--;
            if(lim==0ll) return -1;
        }
    }
    return (n-1)*m;
}
void plus(int n, int m, vvll &cnt, vvll &rcnt) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cnt[i][j]+=rcnt[i][j];
        }
    }
}
void print(ll ser, pll mnmx) {
    printf("%lld %lld %lld\n", mnmx.second, mnmx.first, ser);
}
int main() {
    ll n,m,k,x,y;
    scanf("%lld%lld%lld%lld%lld",&n,&m,&k,&x,&y);

    if(n==1) {
        ll ret = count_forward(n,m,x,y,cnt,0,k);
        if(ret<0) {
            print(getser(n,m,x,y,cnt), getmnmx(n,m,x,y,cnt));
            return 0;
        }

        ll d=0ll;
        k-=ret;
        d+=ret;

        ll mul = k/d+1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cnt[i][j]*=mul;
            }
        }
        k%=d;
        if(k==0) {
            print(getser(n,m,x,y,cnt), getmnmx(n,m,x,y,cnt));
            return 0;
        }

        ret = count_forward(n,m,x,y,cnt,0,k);
        if(ret<0) {
            print(getser(n,m,x,y,cnt), getmnmx(n,m,x,y,cnt));
            return 0;
        } else {
            k-=ret;
            d+=ret;
        }

    }

    ll ret = count_forward(n,m,x,y,cnt,0,k);
    if(ret<0) {
        print(getser(n,m,x,y,cnt), getmnmx(n,m,x,y,cnt));
        return 0;
    } else k-=ret;
    ret = count_backward(n,m,x,y,cnt,k);
    if(ret<0) {
        print(getser(n,m,x,y,cnt), getmnmx(n,m,x,y,cnt));
        return 0;
    } else k-=ret;

    ll d=0ll;
    ret = count_forward(n,m,x,y,rcnt,1,k);
    if(ret<0) {
        plus(n,m,cnt,rcnt);
        print(getser(n,m,x,y,cnt), getmnmx(n,m,x,y,cnt));
        return 0;
    } else {
        k-=ret;
        d+=ret;
    }
    ret = count_backward(n,m,x,y,rcnt,k);
    if(ret<0) {
        plus(n,m,cnt,rcnt);
        print(getser(n,m,x,y,cnt), getmnmx(n,m,x,y,cnt));
        return 0;
    } else {
        k-=ret;
        d+=ret;
    }

    ll mul = k/d+1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            rcnt[i][j]*=mul;
        }
    }
    k%=d;
    if(k==0) {
        plus(n,m,cnt,rcnt);
        print(getser(n,m,x,y,cnt), getmnmx(n,m,x,y,cnt));
        return 0;
    }

    ret = count_forward(n,m,x,y,rcnt,1,k);
    if(ret<0) {
        plus(n,m,cnt,rcnt);
        print(getser(n,m,x,y,cnt), getmnmx(n,m,x,y,cnt));
        return 0;
    } else {
        k-=ret;
        d+=ret;
    }
    ret = count_backward(n,m,x,y,rcnt,k);
    if(ret<0) {
        plus(n,m,cnt,rcnt);
        print(getser(n,m,x,y,cnt), getmnmx(n,m,x,y,cnt));
        return 0;
    } else {
        k-=ret;
        d+=ret;
    }
    return 0;
}

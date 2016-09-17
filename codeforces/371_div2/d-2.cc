//By Endagorion, contest: Codeforces Round #371 (Div. 1), problem: (B) Searching Rectangles, Accepted, #

#include <iostream>
#include <cassert>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
int n;
int ask(int x1, int y1, int x2, int y2) {
    cout << "? " << x1+1 << ' ' << y1+1 << ' ' << x2 << ' ' << y2 << endl;
    int x; cin >> x;
    return x;
}
int tryx() {
    int l=0, r=n;
    while(r-l>1) {
        int m = (l+r)/2;
        (ask(0,0,m,n)>=1?r:l) = m;
    }
    if(ask(0,0,r,n)==1 && ask(r,0,n,n)==1) return r;
    return -1;
}
int tryy() {
    int l=0, r=n;
    while(r-l>1) {
        int m = (l+r)/2;
        (ask(0,0,n,m) >=1? r:l) = m;
    }
    if(ask(0,0,n,r)==1 && ask(0,r,n,n)==1) return r;
    return -1;
}
pair<pii, pii> locate(int lx, int ly, int rx, int ry) {
    for(int i=19; i>=0; i--) {
        int sh = 1<<i;
        if(lx+sh < rx && ask(lx+sh,ly,rx,ry)) lx += sh;
        if(rx-sh > lx && ask(lx,ly,rx-sh,ry)) rx -= sh;
        if(ly+sh < ry && ask(lx,ly+sh,rx,ry)) ly += sh;
        if(ry-sh > ly && ask(lx,ly,rx,ry-sh)) ry -= sh;
    }
    return mp(mp(lx,ly), mp(rx,ry));
}
void print(pair<pii, pii> p) {
    cout << p.fi.fi+1 << ' ' << p.fi.se+1 << ' ' << p.se.fi << ' ' << p.se.se << ' ';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    cin >> n;
    int p;
    pair<pii, pii> r1,r2;
    if((p=tryx())!=-1) {
        r1 = locate(0,0,p,n);
        r2 = locate(p,0,n,n);
    } else if((p=tryy())!=-1) {
        r1 = locate(0,0,n,p);
        r2 = locate(0,p,n,n);
    } else assert(false);
    cout << "! ";
    print(r1); print(r2);
    cout << endl;
    return 0;
}

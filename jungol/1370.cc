#include <iostream>
#include <fstream>

#include <stdio.h>
#include <string.h>
using namespace std;
struct Info{
    int t,s,e;
    Info(){} Info(int t, int s, int e):t(t),s(s),e(e){}
    inline bool operator<(const Info &rhs) const {
        if(e==rhs.e) return s>rhs.s;
        else return e<rhs.e;
    }
    ostream& operator<<(ostream &os, const Info &rhs) const;
};
ostream& operator<<(ostream &os, const Info &rhs) {
    os << rhs.t << " ";
    return os;
}
Info v[501],sorted[501];
int cnt[502], whv[502];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        int t,s,e;
        scanf("%d%d%d",&t,&s,&e);
        v[i]=Info(t,s,e);
    }

    memset(cnt,0,sizeof(cnt));
    for(int i=1; i<=n; i++) cnt[v[i].s]++;
    for(int i=1; i<=n; i++) cnt[i]+=cnt[i-1];
    for(int i=n; i>=1; i--) whv[cnt[v[i].s]--]=i;

    memset(cnt,0,sizeof(cnt));
    for(int i=1; i<=n; i++) cnt[v[whv[i]].e]++;
    for(int i=1; i<=n; i++) cnt[whv[i]]+=cnt[whv[i]-1];
    for(int i=n; i>=1; i--) sorted[--cnt[v[whv[i]].e]] = v[whv[i]];

    for(int i=1; i<=n; i++) {
        cout << sorted[i] << "\n";
    }

    return 0;
}

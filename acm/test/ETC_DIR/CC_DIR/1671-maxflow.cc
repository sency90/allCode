#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Sang{
    ll sz,ve,in;
    Sang(){} Sang(ll sz, ll ve, ll in):sz(sz),ve(ve),in(in){}
};
vector<Sang> sang;
vector<int> v[2002];
int r[2002][2002], p[2002];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        ll sz,ve,in;
        scanf("%lld%lld%lld",&sz,&ve,&in);
        sang.push_back(Sang(sz,ve,in));
    }
    auto cmp = [](const Sang &l, const Sang &r)->bool{
        if(l.sz>=r.sz && l.ve>=r.ve && l.in>=r.in) {
            if(l.sz==r.sz&&l.ve==r.ve&&l.in==r.in) return false;
            else return true;
        } else return false;
    };
    auto cmp2 = [](const Sang &l, const Sang &r)->bool{
        return l.sz==r.sz && l.ve==r.ve && l.in==r.in;
    };
    int src=2*n, sink=2*n+1;
    for(int i=0; i<n; i++) {
        v[src].push_back(i); v[i].push_back(src); r[src][i]+=2;
        v[i+n].push_back(sink); v[sink].push_back(i+n); r[i+n][sink]++;
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            if(cmp(sang[i],sang[j])||(i<j && cmp2(sang[i],sang[j]))) {
                v[i].push_back(j+n);
                v[j+n].push_back(i);
                r[i][j+n]=1;
            }
        }
    }

    int death=0;
    while(true) {
        queue<int> q;
        memset(p,-1,sizeof(p));
        p[src]=src; q.push(src);
        while(!q.empty() && p[sink]==-1) {
            int x=q.front(); q.pop();
            for(auto &y: v[x]) {
                if(p[y]!=-1||r[x][y]<=0) continue;
                p[y]=x;
                q.push(y);
            }
        }
        if(p[sink]==-1) break;
        int mnf=0x3f3f3f3f;
        for(int i=sink; i!=src; i=p[i]) mnf=min(mnf,r[p[i]][i]);
        for(int i=sink; i!=src; i=p[i]) {
            r[p[i]][i]-=mnf;
            r[i][p[i]]+=mnf;
        }
        death+=mnf;
    }
    printf("%d", n-death);
    /*
    int cnt=0;
    for(int i=n; i<n+n; i++) {
        if(r[i][sink]>0) cnt++;
    }
    printf("%d\n", cnt);
    */
    return 0;
}

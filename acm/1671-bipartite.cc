#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct Sang{
    int sz,ve,in;
    Sang(){} Sang(int sz, int ve, int in):sz(sz),ve(ve),in(in){}
};
vector<Sang> sang;
vector<int> v[2002];
int bM[2002], aM[2002];
bool chk[2002];
bool bipartite(int x) {
    if(chk[x]) return false;
    chk[x]=true;
    for(auto &y: v[x]) {
        if(bM[y]==-1||bipartite(bM[y])) {
            bM[y]=x; aM[x]=y;
            return true;
        }
    }
    return false;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int sz,ve,in;
        scanf("%d%d%d",&sz,&ve,&in);
        sang.push_back(Sang(sz,ve,in));
    }
    auto cmp = [](const Sang &l, const Sang &r)->bool{
        if(l.sz>=r.sz && l.ve>=r.ve && l.in>=r.in) {
            return !(l.sz==r.sz&&l.ve==r.ve&&l.in==r.in);
        } else return false;
    };
    auto cmp2 = [](const Sang &l, const Sang &r)->bool{
        return l.sz==r.sz && l.ve==r.ve && l.in==r.in;
    };
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            if(cmp(sang[i],sang[j])||(i<j && cmp2(sang[i],sang[j]))) {
                v[i].push_back(j);
                v[i+n].push_back(j);
            }
        }
    }
    memset(bM,-1,sizeof(bM));
    int death=0, lim=n*2;
    for(int i=0; i<lim; i++) {
        memset(chk,false,sizeof(chk));
        if(bipartite(i)) death++;
    }
    printf("%d\n",n-death);
    return 0;
}

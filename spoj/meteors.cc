#include <cstdio>
#include <vector>
using namespace std;
typedef unsigned long long ull;
vector<int> sect[300001];
vector<vector<int> > cp;
ull goal[300001];
struct Day{
    int l,r; ull cnt;
    Day(){} Day(int l, int r, ull cnt):l(l),r(r),cnt(cnt){}
};
struct Fenwick{
    int s,e;
    vector<ull> tree, tadd;
    Fenwick(){} Fenwick(int n):s(1),e(n),tree(n+1,0ULL){}
    void clear() { tree.clear(); tree.resize(e+1,0ULL); }
    void rupdate(int left, int right, ull by) {
        inupdate(left, by);
        inupdate(right+1, -by);
    }
    void inupdate(int at, ull by) {
        for(int i=at; i<=e && i; i+=i&-i) tree[i]+=by;
    }
    ull query(int at) {
        ull ans=0ULL;
        for(int i=at; i>=1; i&=(i-1)) ans+=tree[i];
        return ans;
    }
};

vector<Day> day(1);
int l[300001], r[300001];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++) {
        int x; scanf("%d",&x);
        sect[x].push_back(i);
    }
    Fenwick fen(m);
    for(int i=1; i<=n; i++) {
        scanf("%llu",&goal[i]);
    }
    int q; scanf("%d",&q);
    for(int i=1; i<=q; i++) {
        int l,r; ull cnt;
        scanf("%d%d%llu",&l,&r,&cnt);
        day.push_back(Day(l,r,cnt));
    }
    cp.resize(q+1, vector<int>());
    for(int i=1; i<=n; i++) l[i]=0, r[i]=q+1;
    while(true) {
        bool good=false;
        for(int i=1; i<=n; i++) {
            if(l[i]+1<r[i]) {
                cp[(l[i]+r[i])>>1].push_back(i);
                good=true;
            }
        }
        if(!good) break;

        int pi=1;
        for(int i=1; i<=q; i++) {
            //bring meteor shower!!
            if(!cp[i].size()) continue;
            for(int j=pi; j<=i; pi=++j) {
                if(day[j].l<=day[j].r) {
                    fen.rupdate(day[j].l,day[j].r,day[j].cnt);
                } else {
                    fen.rupdate(1,day[j].r,day[j].cnt);
                    fen.rupdate(day[j].l,m,day[j].cnt);
                }
            }

            for(int nara: cp[i]) {
                ull sum=0ULL;
                for(int k: sect[nara]) sum+=fen.query(k);
                int mid=(l[nara]+r[nara])>>1;
                if(sum>=goal[nara]) r[nara]=mid;
                else l[nara]=mid;
            }
            cp[i].clear();
        }
        fen.clear();
    }

    for(int i=1; i<=n; i++) {
        if(r[i]!=q+1) printf("%d\n", r[i]);
        else puts("NIE");
    }
    return 0;
}

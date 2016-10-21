#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> sect[300001], day[300001];
vector<vector<int> > cp;
int goal[300001];
struct Day{
    int l,r,cnt;
    Day(){} Day(int l, int r, int cnt):l(l),r(r),cnt(cnt){}
};
struct Fenwick{
    int s,e;
    vector<int> tree;
    Fenwick(int n):s(1),e(n){
        tree.resize(n+1,0);
    }
    add(int r, int s, int e)
};
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++) {
        int x; scanf("%d",&x);
        sect[x].push_back(i);
    }
    for(int i=1; i<=n; i++) {
        scanf("%d",&goal[i]);
    }
    int q; scanf("%d",&q);
    for(int i=1; i<=q; i++) {
        int l,r,cnt;
        scanf("%d%d%d",&l,&r,&cnt);
        d.push_back(Day(l,r,a));
    }
    cp.resize(q+1, vector<int>());
    for(int i=1; i<=n; i++) l[i]=0, r[i]=q+1; //나라 마다 언제 완성될 건지를 판단하는 left, right
    while(true) {
        for(int i=1; i<=n; i++) {
            if(l[i]+1<r[i]) {
                cp[(l[i]+r[i])>>1].push_back(i); //처음에는 중간 날짜에 모두 돌을 다 모은다고 치는거지.
            }
        }

        for(int i=1; i<=q; i++) {
            if(!cp[i].size()) continue;

            for(auto &nara: cp[i]) {
                ll sum=0LL;
                if(day[i].l<=day[i].r) {
                    for( auto &k: sect[nara]) {
                        if(day[i].l<=k && k<=day[i].r) {
                            sum+=day[i].cnt;
                        }
                    }
                } else {
                    for(auto &k: sect[nara]) {
                        if(k<=day[i].l||day[i].r<=k) {
                            ps[nara]+=day[i].cnt;
                        }
                    }
                }

                if(sum>=goal[nara]) r[i]=((l[i]+r[i])>>1);
                else l[i]=(l[i]+r[i])>>1;
            }
        }
    }
    return 0;
}

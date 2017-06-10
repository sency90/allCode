#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct Info{
    int x,y,idx;
    Info(){} Info(int x, int y, int idx):x(x),y(y),idx(idx){}
    bool operator<(const Info &rhs) const {
        return y<rhs.y;
    }
};
bool cmp(const Info &l, const Info &r) {
    if(l.x==r.x) return l.y<r.y;
    else return l.x<r.x;
}
vector<Info> v,z;
vector<int> ans;
int rem[100001],p[100001];
bool chk[100001];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x,y;
        scanf("%d%d", &x,&y);
        v.push_back(Info(x,y,i));
        rem[i]=x;
    }
    for(int i=0; i<=n; i++) p[i]=i;
    sort(v.begin(), v.end(), cmp);
    int last=0;
    for(int i=0; i<n; i++) {
        vector<Info>::iterator it = lower_bound(z.begin(), z.end(), v[i]);
        if(it == z.end()) {
            if(!z.empty()) {
                p[v[i].idx]=z.back().idx;
            }
            z.push_back(v[i]);
            last=v[i].idx;
        } else {
            int idx=it-z.begin();
            if(idx!=0) {
                p[v[i].idx]=z[idx-1].idx;
            }
            *it=v[i];
        }
    }
    printf("%d\n",n-(int)z.size());
    chk[last]=true;
    for(int i=last; i!=p[i]; i=p[i]) {
        chk[p[i]]=true;
    }
    for(int i=0; i<n; i++) {
        if(!chk[i]) ans.push_back(rem[i]);
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++) printf("%d\n", ans[i]);
    return 0;

}


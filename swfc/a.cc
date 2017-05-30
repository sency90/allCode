#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
bool chk[300010];
struct Info{
    int len, s;
    Info(){} Info(int len, int s):len(len),s(s){}
    bool operator<(const Info &rhs) const {
        if(len == rhs.len) return s > rhs.s;
        else return len < rhs.len;
    }
};
typedef Info pii;
vector<pii> v;
priority_queue<pii> mxh;
int main() {
    int m,n,q;
    scanf("%d%d%d",&m,&n,&q);
    for(int i=0; i<n; i++) {
        int x; scanf("%d",&x);
        chk[x]=true;
    }
    for(int i=0; i<q; i++) {
        int x; scanf("%d",&x);
        v.push_back(pii(x,0));
    }

    chk[0]=chk[m+1]=true;
    int s=0,e=0;
    for(int i=0; i<=m+1; i++) {
        if(chk[i]) {
            if(e>s) mxh.push(pii(e-s,s+1));
            s=i;
        } else e=i;
    }

    pii tmp;
    int i=0;
    while(!mxh.empty()) {
        tmp = mxh.top(); mxh.pop();
        int mid = tmp.s + (tmp.len-1)/2;
        v[i++].s = mid;
        int ls=tmp.s, le=mid-1, rs=mid+1, re=tmp.len+tmp.s-1;
        if(le>=ls) mxh.push(pii(le-ls+1,ls));
        if(re>=rs) mxh.push(pii(re-rs+1,rs));
        if(i==v.size()) break;
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        printf("%d\n", v[i].s);
    }
    return 0;
}

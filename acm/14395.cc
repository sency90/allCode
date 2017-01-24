#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
struct Info{
    ll x;
    int idx, sz;
    Info():x(0),idx(0),sz(0){} Info(ll x, int idx, int sz):x(x),idx(idx),sz(sz){}
    bool operator<(const Info& rhs) const {
        if(sz==rhs.sz) {
            if(x==rhs.x) return idx>rhs.idx;
            else return x<rhs.x;
        } else return sz > rhs.sz;
    }
};
priority_queue<Info> h;
string str;
vector<int> prv;
int main() {
    ll s,e;
    scanf("%lld%lld",&s,&e);
    if(s==e) puts("0");
    else if(e==0) puts("-");
    else if(s==0 && e!=0) puts("-1");
    else if(e==1) puts("/");
    else {
        string ans;
        int idx=0;
        str+='0';
        prv.push_back(idx);
        h.push(Info(s,idx++,0));
        if(e%2==0) {
            str+='/';
            prv.push_back(idx);
            h.push(Info(1,idx++,1));
        }
        while(!h.empty()) {
            Info info = h.top(); h.pop();
            if(info.x==e) {
                int i=info.idx;
                for(; i!=prv[i]; i=prv[i]) ans=str[i]+ans;
                if(prv[i]==1) ans=str[prv[i]]+ans;
                return 0&printf("%s", ans.c_str());
            } else if(info.x>e) continue;

            if(info.x!=1) {
                str+='*';
                prv.push_back(info.idx);
                h.push(Info(info.x*info.x, idx++, info.sz+1));
            }
            str+='+';
            prv.push_back(info.idx);
            h.push(Info(info.x*2, idx++, info.sz+1));
        }
        puts("-1");
    }
    return 0;
}

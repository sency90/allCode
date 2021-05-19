#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
int v[3][3];
struct Info{
    int zi; ll s;
    Info():zi(0),s(0LL){}
    Info(int zi, ll s):zi(zi),s(s) {}
    bool operator<(const Info & rhs) const {
        if(zi == rhs.zi) return s < rhs.s;
        else return zi<rhs.zi;
    }
};
queue<Info> q;
map<Info,bool> chk;
int dx[] = {0,1,0,-1}, dy[]={1,0,-1,0};
ll chg(int zi, int nzi, ll s) {
    zi = (8-zi)*4LL, nzi = (8-nzi)*4LL;
    ll mask = 0xfLL;
    ll a = ((s&(mask<<zi))>>zi)&mask;
    ll b = ((s&(mask<<nzi))>>nzi)&mask;
    ll c = s&(~(mask<<zi))&(~(mask<<nzi));
    return (a<<nzi)|(b<<zi)|c;
}
int main() {
    ll state=0, suc_state=0;
    int zi=0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            ll x; scanf("%lld", &x);
            state = ((state)<<4)|x;
            if(x==0LL) zi = i*3+j;
        }
    }
    ll k=1LL;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(k==9LL) k=0LL;
            suc_state = ((suc_state)<<4)|k++;
        }
    }
    q.emplace(zi, state);
    chk[Info(zi,state)] = true;
    int cnt=0;
    while(!q.empty()) {
        int sz = q.size();
        for(int z=0; z<sz; z++) {
            Info info = q.front(); q.pop();
            if(info.s == suc_state) {
                return 0&printf("%d\n", cnt);
            }
            int x=info.zi/3, y=info.zi%3;
            for(int i=0; i<4; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if(nx<0||ny<0||nx>=3||ny>=3) continue;

                int nzi = nx*3+ny;
                ll ns = chg(info.zi, nzi, info.s);
                if(chk.count(Info(nzi,ns))>0) continue;
                q.emplace(nzi,ns);
                chk[Info(nzi,ns)] = true;
            }
        }
        cnt++;
    }
    puts("-1");
    return 0;
}

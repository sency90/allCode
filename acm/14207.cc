#include <cstdio>
#include <vector>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
vector<int> a,b;
queue<int> q;
bool chk[1001];
int gcd(int b, int s) { return s?gcd(s,b%s):b; }
ll lcm(ll a, ll b) { return a*b/gcd(a,b); }
int main() {
    int n,s,t,m;
    scanf("%d%d%d%d",&n,&s,&t,&m);
    a.resize(m); b.resize(m);
    for(int i=0; i<m; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) {
        scanf("%d", &b[i]);
        if(s%a[i]==0) {
            q.push(i);
            chk[i]=true;
        }
    }

    int cnt=1;
    while(!q.empty()) {
        int sz=q.size();
        for(int z=0; z<sz; z++) {
            int idx=q.front(); q.pop();
            if(t%b[idx]==0) return 0&printf("%d", cnt);
            for(int i=0; i<m; i++) {
                ll l = lcm(a[i],b[idx]);
                if(l<n) {
                    if(chk[i]) continue;
                    chk[i]=true;
                    q.push(i);
                }
            }
        }
        cnt++;
    }
    puts("-1");
    return 0;
}

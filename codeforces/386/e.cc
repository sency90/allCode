#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int v[100001], ans[100001];
vector<int> oddpos, evenpos;
map<int,int> odd,even;
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
        if(v[i]%2) odd[v[i]]=false;
        else even[v[i]]=false;
    }
    int half=n>>1, lim = min(200000,m), cnt=0;
    for(int i=2; i<=lim; i+=2) {
        if(even.size()==half) break;
        if(even.count(i) == 0) {
            even[i]=false;
            cnt++;
        }
    }
    for(int i=1; i<=lim; i+=2) {
        if(odd.size()==half) break;
        if(odd.count(i) == 0) {
            odd[i]=false;
            cnt++;
        }
    }
    if(even.size()==half && odd.size()==half) {
        printf("%d\n", cnt);
        for(int i=0; i<n; i++) {
            if(v[i]%2==0) {
                if(even.count(v[i])) {
                    if(!even[v[i]]) {
                        even[v[i]]=true;
                        ans[i]=v[i];
                    } else evenpos.push_back(i);
                } else evenpos.push_back(i);
            } else {
                if(odd.count(v[i])) {
                    if(!odd[v[i]]) {
                        odd[v[i]]=true;
                        ans[i]=v[i];
                    } else oddpos.push_back(i);
                } else oddpos.push_back(i);
            }
        }
        int idx=0;
        for(auto &p: even) {
            if(!p.second) ans[evenpos[idx++]]=p.first;
        }
        idx=0;
        for(auto &p: odd) {
            if(!p.second) ans[oddpos[idx++]]=p.first;
        }
        for(int i=0; i<n; i++) printf("%d ", ans[i]);
    } else puts("-1");

    return 0;
}

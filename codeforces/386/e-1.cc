#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int v[200001], ans[200001];
set<int> odd,even;
vector<int> anspos, nopos;
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
        if(v[i]%2) odd.insert(v[i]);
        else even.insert(v[i]);
    }
    int half=n>>1, lim = min(400000,m), cnt=0;
    for(int i=2; i<=lim; i+=2) {
        if(even.size()==half) break;
        if(even.count(i) == 0) {
            even.insert(i);
            cnt++;
        }
    }
    for(int i=1; i<=lim; i+=2) {
        if(odd.size()==half) break;
        if(odd.count(i) == 0) {
            odd.insert(i);
            cnt++;
        }
    }
    if(even.size()==half && odd.size()==half) {
        printf("%d\n", cnt);
        for(int i=0; i<n; i++) {
            if(v[i]%2==0) {
                if(even.count(v[i])) {
                    even.erase(v[i]);
                    ans[i]=v[i];
                } else nopos.push_back(i);
            } else {
                if(odd.count(v[i])) {
                    odd.erase(v[i]);
                    ans[i]=v[i];
                } else nopos.push_back(i);
            }
        }
        int idx=0;
        for(int p: odd) ans[nopos[idx++]]=p;
        for(int p: even) ans[nopos[idx++]]=p;
        for(int i=0; i<n; i++) printf("%d ", ans[i]);
    } else puts("-1");
    return 0;
}

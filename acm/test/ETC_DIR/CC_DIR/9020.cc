#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
bool noPrime[11001];
vector<int> v;
pii find(int x) {
    for(auto it = lower_bound(v.begin(), v.end(), x/2); it!=v.end(); it++) {
        auto jt = lower_bound(v.begin(), v.end(), (x - *it));
        if(*jt == (x-*it)) return pii(*jt, *it);
    }
    return pii(0,0); //err
}
int main() {
    pii ans;
    noPrime[0] = noPrime[1] = true;
    for(int i=2; i*i<=11000; i++) {
        if(noPrime[i]) continue;
        for(int j=i*i; j<=11000; j+=i) {
            noPrime[j] = true;
        }
    }
    for(int i=0; i<=10000; i++) {
        if(!noPrime[i]) v.push_back(i);
    }
    int n,x; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        ans = find(x);
        printf("%d %d\n", ans.first, ans.second);
    }
    return 0;
}


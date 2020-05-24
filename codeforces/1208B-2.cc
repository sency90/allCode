#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
map<int,int> dic;
vector<int> a,mni,mxi;
vector<pii> p;
const int inf = 0x3f3f3f3f;
int main() {
    int n; cin >> n;
    a.clear(); a.resize(n+1, 0);

    int sidx=-1;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        p.emplace_back(a[i],i);
        if(sidx<0 && ++dic[a[i]] >=2) sidx = i;
    }
    if(sidx<0) return 0&puts("0");

    sort(p.begin(), p.end());

    mxi.clear(); mxi.resize(n+2,0);
    mni.clear(); mni.resize(n+2,inf);
    for(int i=1; i<=n; i++) {
        auto it = lower_bound(p.begin(), p.end(), pii(a[i],inf))-1; //a[i]값을 가진 인덱스i의 최대값을 찾는다.
        mxi[i] = it->second;
        if(i==1) mxi[i] = 1;
        else mxi[i] = max(mxi[i-1],mxi[i]);
    }

    for(int i=n; i>=1; i--) {
        auto it = lower_bound(p.begin(), p.end(), pii(a[i],-1)); //a[i]값을 가진 인덱스i의 최소값을 찾는다.
        mni[i] = (it-1)->second;
        if(i==n) mni[i] = n;
        else mni[i] = min(mni[i+1],mni[i]);
    }

    int ans = inf;
    for(int i=1; i<sidx; i++) {
        int val = a[i];
        auto it = lower_bound(p.begin(), p.end(), pii(val,-1));
        auto jt = lower_bound(p.begin(), p.end(), pii(val,inf))-1;

        if(mxi[it->second] < jt->second+1 && it->second < mni[jt->second+1]) {
            printf("%d < %d  &&  %d < %d\n",mxi[it->second], jt->second+1, it->second,  mni[jt->second+1]);
            ans = min(ans, int(jt->second + it->second));
        }
    }
    printf("%d", ans);
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
vector<int> a;
vector<pii> b;
map<int,int> dic;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int sidx=-1, eidx=-1;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        a.push_back(x);
        b.emplace_back(x,i);
        if(sidx<0 && ++dic[x] == 2) {
            sidx = i;
        }
    }
    dic.clear();
    for(int i=n-1; i>=0; i--) {
        if(eidx<0 && ++dic[a[i]] == 2) {
            eidx = i;
            break;
        }
    }

    if(sidx<0 && eidx<0) return 0&puts("0");

    sort(b.begin(), b.end());

    int ans = n-1;
    const int inf = 0x3f3f3f3f;
    auto it = upper_bound(b.begin(), b.end(), pii(a.back(),inf))-1;
    if(it!=b.begin()) {
        int idx = (it-1)->second;
        if(idx>eidx) ans = min(ans, idx+1);
    } else ans = n-1;

    dic.clear();
    for(int i=0; i<sidx; i++) {
        dic[a[i]]++;
        auto it = upper_bound(b.begin(), b.end(), pii(a[i], inf))-1;

        //auto it = upper_bound(b.rbegin(), b.rend(), pii(a[i],inf)).base();
        int idx = it->second;
        if(idx>eidx) {
            printf("a[i:%d]:%d, a[idx:%d]:%d\n",i,a[i],idx,a[idx]);
            if(idx>=i) ans = min(ans, idx-i);
        } else ans = min(ans, eidx-i);
    }
    printf("%d", ans);
    return 0;
}

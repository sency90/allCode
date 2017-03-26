#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> sl, sr;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; scanf("%d", &n);
    int l,r;
    for(int i=0; i<n; i++) {
        scanf("%d%d",&l,&r);
        sl.push_back(l);
        sr.push_back(r);
    }
    sort(sl.begin(), sl.end());
    sort(sr.begin(), sr.end());
    int m; scanf("%d", &m);
    int mx=0;
    for(int i=0; i<m; i++) {
        scanf("%d%d",&l,&r);
        mx=max(l-sr[0],mx);
        mx=max(sl[n-1]-r,mx);
    }
    printf("%d\n", mx);
    return 0;
}

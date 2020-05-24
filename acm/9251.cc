#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define v2 (v<<1)
string a,b,A,B;
inline int chg(char c) {
    return c-'A';
}
vector<int> pos[26];
int seg[2049];
int query(int v, int s, int e, int l, int r) {
    if(r<s || e<l || l>r) return 0;
    else if(l<=s && e<=r) return seg[v];
    else return max(query(v2, s, (s+e)/2, l, r), query(v2+1, (s+e)/2+1, e, l, r));
}
int update(int v, int s, int e, int at, int val) {
    if(at<s || e<at) return 0;
    else if(s==e && s==at) return seg[v] = val;
    else {
        int mx = max(update(v2,s,(s+e)/2,at,val), update(v2+1,(s+e)/2+1,e,at,val));
        return seg[v] = max(mx, seg[v]);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> a >> b;

    for(int i=0; i<b.size(); i++) {
        pos[chg(b[i])].push_back(i);
    }

    int i;
    for(i=0; i<=10; i++) {
        if((1<<i)>(int)b.size()) break;
    }
    int s=1, e=(1<<i);
    int ans = 0;
    for(int i=0; i<a.size(); i++) {
        if(pos[chg(a[i])].empty()) continue;
        for(int j=pos[chg(a[i])].size()-1; j>=0; j--) {
            int mx = query(1,s,e,1,pos[chg(a[i])][j]);
            update(1,s,e,pos[chg(a[i])][j]+1, mx+1);
        }
    }

    printf("%d", seg[1]);
    return 0;
}

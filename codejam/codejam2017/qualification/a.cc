#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
void chg(int idx, string &s, int k) {
    for(int i=idx; i<idx+k; i++) {
        if(s[i]=='-') s[i]='+';
        else s[i]='-';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n,k; cin >> n;

    for(int z=1; z<=n; z++) {
        string s=""; cin >> s >> k;
        int ans=0, len=s.size();
        for(int i=0; i<len; i++) {
            if(i<=len-k) {
                if(s[i]=='-') {
                    chg(i,s,k);
                    ans++;
                }
            } else {
                if(s[i]=='-') {
                    ans=inf;
                    break;
                }
            }
        }
        printf("Case #%d: ", z);
        if(ans>=inf) puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }
    return 0;
}

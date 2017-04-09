#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n; cin >> n;
    for(int z=1; z<=n; z++) {
        string s,tmp;
        cin >> s;
        ll ans=0LL;
        int start=-1;
        for(int i=s.size()-1; i>=1; i--) {
            int cv=s[i-1]-'0', pv=s[i]-'0';
            if(cv>pv) {
                start=i;
                s[i-1]=cv-1+'0';
            }
        }
        if(start>=0) {
            for(int i=0; i<start; i++) tmp[i]=s[i];
            for(int i=start; i<s.size(); i++) tmp[i]='9';
        } else tmp=s;
        ans = stoll(tmp);
        printf("Case #%d: %lld\n", z,ans);
    }
    return 0;
}

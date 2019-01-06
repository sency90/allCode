#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
vector<int> cones, snows, sum;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s, ns;
    int n;
    cin >> s >> n;
    for(int i=0,j=0; i<s.size(); i++) {
        if(s[i]=='?') cones.push_back(j-1);
        else if(s[i]=='*') snows.push_back(j-1);
        else {
            j++;
            ns+=s[i];
        }
    }
    int len = ns.size();

    string ans="";
    int mn = len - (int(cones.size())+int(snows.size()));
    int mx = (snows.size()>0)?inf:len;
    if(mn <= n && n<= mx) {
        if(n > len) {
            int cnt = n-len;
            if(snows.empty()) return 0&puts("Impossible");
            for(int i=0; i<=snows[0]; i++) ans += ns[i];
            for(int i=0; i<cnt; i++) ans += ns[snows[0]];
            for(int i=snows[0]+1; i<ns.size(); i++) ans+=ns[i];
            ans = ns.substr(0,snows[0]+1);
            for(int i=0; i<cnt; i++) ans += ns[snows[0]];
            ans += ns.substr(snows[0]+1);
        }
        else if(n == len) {
            ans = ns;
        } else {
            int cnt = len-n;
            for(int i=0; i<cones.size(); i++) sum.push_back(cones[i]);
            for(int i=0; i<snows.size(); i++) sum.push_back(snows[i]);
            sort(sum.begin(), sum.end());
            int idx=0;
            bool hasAns = false;
            for(int i=0; i<ns.size(); i++) {
                if(!hasAns && idx<sum.size() && (i == sum[idx])) {//같으면 넣지마.
                    idx++;
                    if(idx>=cnt) hasAns=true;
                } else ans+=ns[i];
            }
        }
        printf("%s\n", ans.c_str());
    } else puts("Impossible");

    return 0;
}

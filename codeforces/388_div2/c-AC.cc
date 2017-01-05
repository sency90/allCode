#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
set<int> s[2];
int cnt[2];
int idx(char x) {
    if(x=='D') return 0;
    else return 1;
}
bool chk[200001];
bool rm(int x, int opp) {
    s[opp].erase(x);
    chk[x]=true;
    return (--cnt[opp] == 0);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string str;
    int n; cin >>n>>str;
    for(int i=0; i<n; i++) {
        int x=idx(str[i]);
        s[x].insert(i);
        cnt[x]++;
    }
    while(cnt[0]!=0&&cnt[1]!=0) {
        for(int i=0; i<n; i++) {
            if(chk[i]) continue;
            int opp = idx(str[i])^1;
            auto it = s[opp].lower_bound(i);
            if(it == s[opp].end()) {
                if(cnt[opp]==0) break;
                else {
                    auto it = s[opp].lower_bound(0);
                    if(it == s[opp].end()) break;
                    else if(rm(*it,opp)) break;
                }
            } else if(rm(*it,opp)) break;
        }
    }
    if(cnt[0]) puts("D");
    else puts("R");
    return 0;
}

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;
vector<int> ans, v[26];
set<int> valid;
string s[101];
int in[26];
int chg(char c) { return c-'a'; }
queue<int> q;
int main() {
    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> s[i];
        for(int j=0; j<s[i].size(); j++) valid.insert(chg(s[i][j]));

        if(i==1) continue;
        int lim = min((int)s[i-1].size(), (int)s[i].size());
        for(int j=0; j<lim; j++) {
            if(s[i-1][j]!=s[i][j]) {
                int pc=chg(s[i-1][j]), c=chg(s[i][j]);
                v[pc].push_back(c);
                in[c]++;
                break;
            }
        }
    }
    for(int i=0; i<26; i++) {
        if(!in[i]&&valid.count(i)) q.push(i);
    }
    int lim=valid.size();
    for(int i=0; i<=lim; i++) {
        if(i!=lim) {
            if((int)q.size()>=2) { puts("?"); return 0; }
            if(q.empty()) { puts("!"); return 0; }
        } else if(q.empty()) break;
        int x=q.front(); q.pop();
        ans.push_back(x);
        for(int y: v[x]) {
            if(--in[y]==0) q.push(y);
        }
    }
    for(auto &p: ans) printf("%c",p+'a');
    return 0;
}

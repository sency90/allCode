#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;
vector<int> ans, v[27];
set<int> valid;
string s[101];
int in[27];
bool chk[27][27];
int chg(char c) {
    if(c==0) return 26;
    else return c-'a';
}
queue<int> q;
int main() {
    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> s[i];
        for(int j=0; j<s[i].size(); j++) valid.insert(chg(s[i][j]));
    }
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            int z,lim = min((int)s[i].size(), (int)s[j].size());
            for(z=0; z<lim; z++) {
                if(s[i][z]!=s[j][z]) {
                    int pc=chg(s[i][z]), c=chg(s[j][z]);
                    if(chk[pc][c]) break;
                    chk[pc][c]=true;
                    v[pc].push_back(c);
                    in[c]++;
                    break;
                }
            }
            if(z==lim && s[i].size()>s[j].size()) {
                puts("!");
                return 0;
            }
        }
    }
    for(int i=0; i<26; i++) {
        if(!in[i]&&valid.count(i)) q.push(i);
    }
    int lim=valid.size();
    for(int i=0; i<lim; i++) {
        if((int)q.size()>=2) { puts("?"); return 0; }
        if(q.empty()) { puts("!"); return 0; }
        int x=q.front(); q.pop();
        ans.push_back(x);
        for(int y: v[x]) {
            if(--in[y]==0) q.push(y);
        }
    }
    for(auto &p: ans) printf("%c",p+'a');
    return 0;
}

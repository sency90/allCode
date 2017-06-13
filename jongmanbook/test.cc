#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef pair<int,int> pii;
vector<vector<pii>> v;
vector<int> ans;
int in[26],out[26];
bool chk[101];
string s[101];
int any;
void input(int x) {
    int a=s[x][0]-'a', b=s[x][s[x].size()-1]-'a';
    v[a].push_back(make_pair(b,x));
    out[a]++; in[b]++;
}
void dfs(int x) {
    for(auto &p: v[x]) {
        if(chk[p.second]) continue;
        chk[p.second]=true;
        dfs(p.first);
        ans.push_back(p.second);
    }
}
int ABS(int x) { return x<0?-x:x; }
bool isValid(int &s, int &e) {
    bool good = true;
    for(int i=0; i<26; i++) {
        if(ABS(in[i]-out[i])>1) return false;
        else if(in[i]!=out[i]) good=false;
    }
    if(good) {
        s=e=any;
        return true;
    }

    s=e=-1;
    for(int i=0; i<26; i++) {
        if(out[i]==in[i]) continue;
        if(out[i]-in[i]==1) {
            if(s<0) s=i;
            else return false;
        } else if(out[i]-in[i]==-1){
            if(e<0) e=i;
            else return false;
        } else return false;
    }
    if(s<0||e<0) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(chk,false,sizeof(chk));
    ans.clear(); v.clear();
    v.resize(26, vector<pii>());

    for(int i=0; i<n; i++) {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
        input(i);
        any=s[i][0]-'a';
    }

    int start,end;
    if(!isValid(start,end)) puts("NO");
    else {
        dfs(start);
        if(ans.size()!=n) puts("NO");
        else puts("YES");
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
string wildcard, str[51];
vector<string> ans_list;
int lim;
bool chk[101][101];
bool dp[101][101];
void Init() {
    memset(chk,false,sizeof(chk));
}
bool dfs(int wi, const string & s, int si, int lim) {
    if(wi==wildcard.size() && si==s.size()) {
        return dp[wi][si] = true;
    }

    if(wi==wildcard.size() && si<s.size()) return false;
    if(s.size()-si<lim) return false;

    if(chk[wi][si]) return dp[wi][si];

    chk[wi][si] = true;
    bool & ret = dp[wi][si];

    ret = false;
    if(wildcard[wi] == '*') {
        //wildcard를 소모하는 경우
        ret |= dfs(wi+1,s,si,lim);
        if(ret) return true;

        //wildcard를 소모하지 않는 경우
        for(int i = si + 1; i <= s.size(); i++) {
            ret |= dfs(wi, s, i, lim);
            if(ret) return true;
        }
    }
    else if(wildcard[wi] == '?') {
        ret |= dfs(wi+1,s,si+1,lim-1);
    }
    else {
        if(wildcard[wi] == s[si]) {
            ret |= dfs(wi+1,s,si+1,lim-1);
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> wildcard;
        int n; cin >> n;
        for(int i=0; i<n; i++) {
            cin >> str[i];
        }

        int cnt=0;
        for(int i=0; i<wildcard.size(); i++) {
            if(wildcard[i] == '*') cnt++;
        }
        lim = wildcard.size()-cnt;

        ans_list.clear();
        for(int i=0; i<n; i++) {
            Init();
            if(dfs(0,str[i],0,lim)) {
                ans_list.emplace_back(str[i]);
            }
        }

        sort(ans_list.begin(), ans_list.end());
        for(int i=0; i<ans_list.size(); i++) {
            printf("%s\n", ans_list[i].c_str());
        }
    }
    return 0;
}
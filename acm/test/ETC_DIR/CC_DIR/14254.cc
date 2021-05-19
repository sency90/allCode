#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
vector<vector<int>> cnt;
vector<int> v[51];
set<int> st;
string s;
bool chk[51];
void dfs(int x) {
    chk[x]=true;
    st.insert(int(s[x]-'a'));
    cnt[s[x]-'a'].push_back(x);
    for(int y: v[x]) {
        if(!chk[y]) {
            dfs(y);
        }
    }
}
int main() {
    int k;
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s >> k;

    int n=s.size(), ans=0;
    for(int i=0,j=n-k; i<k; i++,j++) {
        v[i].push_back(j);
    }
    for(int i=0; i<k; i++) {
        if(!chk[i]) {
            cnt.clear();
            cnt.resize(26,vector<int>());
            st.clear();
            dfs(i);
            auto it = st.begin();
            int mx=cnt[*it].size(), mxi=*it;
            for(auto &j : st){
                if(mx<cnt[j].size()) {
                    mx=cnt[j].size();
                    mxi=j;
                }
            }
            for(auto &j : st) {
                if(j!=mxi) {
                    ans+=cnt[j].size();
                    for(int z: cnt[j]) {
                        s[z]=mxi+'a';
                    }
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}

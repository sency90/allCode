#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
map<string, int> mp;
string s;
vector<vector<int>> v;
vector<int> am, bm;
bool chk[2800];
bool bipartite(int x) {
    if(chk[x]) return false;
    chk[x]=true;
    for(int y: v[x]) {
        if(!bm[y]||bipartite(bm[y])) {
            am[x]=y;
            bm[y]=x;
            return true;
        }
    }
    return false;
} int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    vector<string> vs({{"RpNuNqSlAmAqArHhSdCiAtJbAjUeUqIuEhP", "rMrQlEpQjSrFnHj", "RrQjRkRbObMpGlBeAhEjBiUhOjFbJeTsKmUeK", "kSoRrHcGeRoRhO", "pSrQeI", "n", "A", "o", "Q", "r", "K", "c", "K", "c", "P", "o", "M", "h", "M", "s", "H", "d", "B", "l", "R", "d", "U", "n", "Q", "t", "E", "u", "B", "k", "P", "m", "P", "b", "F", "j", "S", "h", "S", "q", "N", "e", "S", "b", "C", "i"}});
    for(auto &p: vs) s+=p;
    //cin >> s;
    int cnt=1;
    for(int i=1; i<s.size(); i++) {
        string ts = s.substr(i-1,2);
        if(mp.count(ts)) continue;
        else mp[ts]=cnt++;
    }

    v.resize(mp.size()+1, vector<int>());
    string f=s.substr(0,2), e=s.substr(s.size()-2,2);
    v[mp[f]].push_back(mp[f]);
    if(f!=e) v[mp[e]].push_back(mp[e]);
    for(int i=1; i<s.size()-1; i++) {
        if(i&1) v[mp[s.substr(i-1,2)]].push_back(mp[s.substr(i,2)]);
        else v[mp[s.substr(i,2)]].push_back(mp[s.substr(i-1,2)]);
    }
    am.resize(mp.size()+1,0);
    bm.resize(mp.size()+1,0);
    int ans=0;
    for(int i=1; i<=mp.size(); i++) {
        memset(chk,false,sizeof(chk));
        if(bipartite(i)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}

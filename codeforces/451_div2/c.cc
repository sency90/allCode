#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
map<string, int> mp;
vector<string> v[21];
string name[21];
bool chk[21],vis[201];
bool contain(string &a, string &b) {
    if(a.size() < b.size()) return false;
    for(int i=b.size()-1, j=a.size()-1; i>=0; i--, j--) {
        if(a[j]!=b[i]) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int cnt=0;
    for(int i=0; i<n; i++) {
        cin >> name[i];
        int idx,num;
        if(mp.count(name[i])) idx=mp[name[i]];
        else {
            idx=mp[name[i]]=cnt;
            cnt++;
        }

        cin >> num;
        string s;
        for(int j=0; j<num; j++) {
            cin >> s;
            v[idx].push_back(s);
        }
    }


    printf("%d\n",cnt);
    memset(chk,false,sizeof(chk));
    for(int i=0; i<n; i++) {
        int idx = mp[name[i]];
        if(chk[idx]) continue;
        chk[idx]=true;
        memset(vis,false,sizeof(vis));
        for(int j=0; j<v[idx].size(); j++) {
            for(int k=0; k<v[idx].size(); k++) {
                if(j==k || vis[k]) continue;
                if(contain(v[idx][k], v[idx][j])) {
                    vis[j]=true;
                    break;
                }
            }
        }
        int tmpcnt=0;
        printf("%s ", name[i].c_str());
        for(int j=0; j<v[idx].size(); j++) {
            if(!vis[j]) tmpcnt++;
        }
        printf("%d ", tmpcnt);
        for(int j=0; j<v[idx].size(); j++) {
            if(!vis[j]) printf("%s ", v[idx][j].c_str());
        } puts("");
    }
    return 0;
}

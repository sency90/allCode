#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cctype>
#include <map>
using namespace std;
char nps[110][110];
vector<string> name, chat;
vector<int> ans;
map<string, int> mp;
int n,m,e;
bool chk[110][110], ccc[110];
int dp[110][110], par[110][110];
int f(int x, int y) {
    int &ret = dp[x][y];
    if(ret) return ret;
    else ret=2;
    if(x>=m-1) {
        if(nps[x][y]=='0') {
            e=y;
            return ret=1;
        } else return ret=2;
    }

    for(int i=0; i<n; i++) {
        if(i==y) continue;
        if(nps[x+1][i]=='0') {
            ret |= f(x+1,i);
            if(ret&1) par[x+1][i]=y;
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        memset(chk, false, sizeof(chk));
        memset(ccc, false, sizeof(ccc));
        memset(dp, 0, sizeof(dp));
        memset(par, -1, sizeof(par));
        memset(nps, '0', sizeof(nps));
        ans.clear(); mp.clear();

        cin >> n;
        name.clear(); name.resize(n);
        for(int i=0; i<n; i++) {
            cin >> name[i];
            mp[name[i]]=i;
        }

        string buf, tmpName;
        cin >> m; getline(cin,buf);
        chat.clear(); chat.resize(m, string());

        for(int i=0; i<m; i++) {
            bool ignor=false;
            getline(cin, chat[i]);
            int k=0; for(; k<chat[i].size(); k++) {
                if(chat[i][k]==':') {
                    tmpName=chat[i].substr(0,k);
                    break;
                }
            }

            string x="";
            if(tmpName=="?") {
                ccc[i]=true;
                for(;k<=chat[i].size(); k++) {
                    if(isalpha(chat[i][k])&&!ignor) x+=chat[i][k];
                    else if(isdigit(chat[i][k])) {
                        if(x=="") {
                            ignor=true;
                            continue;
                        } else x+=chat[i][k];
                    } else {
                        ignor=false;
                        if(x=="") continue;
                        if(mp.count(x)) nps[i][mp[x]]='1';
                        x="";
                    }
                }
            } else {
                if(mp.count(tmpName)) {
                    int idx=mp[tmpName];
                    for(int k=0; k<n; k++) {
                        if(k==idx) nps[i][k]='0';
                        else nps[i][k]='1';
                    }
                }
            }
        }

        bool good = false;
        for(int i=0; i<n; i++) {
            if(nps[0][i]=='0') {
                if(f(0,i)&1) {
                    good = true;
                    for(int j=e, X=m-1; X>0; j=par[X--][j]) ans.push_back(j);
                    ans.push_back(i);
                    break;
                }
            }
        }
        if(!good) puts("Impossible");
        else {
            reverse(ans.begin(), ans.end());
            for(int i=0; i<m; i++) {
                if(ccc[i]) printf("%s%s\n", name[ans[i]].c_str(), chat[i].substr(1, chat[i].size()-1).c_str());
                else printf("%s\n", chat[i].c_str());
            }
        }
    }
    return 0;
}

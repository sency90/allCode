#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
set<string> st[201][14];
string pre[201], sfx[201], s[101];
const int mx = 13;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s[i];
        for(int j=0; j<s[i].size(); j++) {
            for(int k=j; k<s[i].size(); k++) {
                int len = k-j+1;
                if(len > mx) break;
                st[i][len].emplace(s[i].begin()+j, s[i].begin()+k+1);
            }
        }

        if(s[i].size()<mx) pre[i] = sfx[i] = s[i];
        else {
            pre[i]=string(s[i].begin(), s[i].begin()+mx);
            sfx[i]=string(s[i].end()-mx, s[i].end());
        }
    }

    int m; cin >> m;
    for(int i=n; i<n+m; i++) {
        int a,b; cin >> a >> b;
        a--; b--;
        for(int j=1; j<=mx; j++) {
            for(auto it : st[a][j]) st[i][j].emplace(it);
            for(auto it : st[b][j]) st[i][j].emplace(it);
        }

        string str = sfx[a]+pre[b];
        for(int j=0; j<str.size(); j++) {
            for(int k=j; k<str.size(); k++) {
                int len = k-j+1;
                if(len > mx) break;
                st[i][len].emplace(str.begin()+j, str.begin()+k+1);
            }
        }

        int ans=1;
        for(; ans<=mx; ans++) if(st[i][ans].size() != (1<<ans)) break;
        printf("%d\n", ans-1);

        if(pre[a].size() >= mx) pre[i]=pre[a];
        else {
            pre[i]=pre[a]+pre[b];
            pre[i]=pre[i].substr(0,min(mx,int(pre[i].size())));
        }

        if(sfx[b].size() >= mx) sfx[i]=sfx[b];
        else {
            sfx[i]=sfx[a]+sfx[b];
            int tmp = min(mx, int(sfx[i].size()));
            sfx[i]=sfx[i].substr(sfx[a].size()+sfx[b].size()-tmp, tmp);
        }
    }
    return 0;
}

#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;
int v[10];
string g[10];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    while(true) {
        memset(v,0,sizeof(v));
        map<string,int> mp;
        string s;
        for(int i=0; i<n; i++) {
            cin >> s;
            mp[s]=i;
            g[i]=s;
        }
        for(int i=0; i<n; i++) {
            int x,y;
            cin >> s >> x >> y;
            if(y==0) continue;
            int b=x/y;
            v[mp[s]]-=b*y;
            for(int j=0; j<y; j++) {
                cin >> s;
                v[mp[s]]+=b;
            }
        }
        for(int i=0; i<n; i++) {
            printf("%s %d\n", g[i].c_str(), v[i]);
        }
        if(cin >> n) puts("");
        else break;
    }
    return 0;
}

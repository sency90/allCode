#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
int dist[51][3], v[51];
string s;
const int inf = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    memset(dist,0x3f,sizeof(dist));
    for(int z=0; z<n; z++) {
        cin >> s;
        int sz = s.size();
        for(int i=0; i<sz; i++) {
            if(isalpha(s[i])) v[i]=0;
            else if(isdigit(s[i])) v[i]=1;
            else v[i]=2;
        }
        for(int i=0,j=sz; i<sz; i++,j--) {
            dist[z][v[i]] = min({dist[z][v[i]],i,j});
        }
    }
    int ans = inf;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            for(int k=0; k<n; k++) {
                if(i==k||j==k) continue;
                if((dist[i][0]|dist[j][1]|dist[k][2])<inf) {
                    ans = min(ans, dist[i][0]+dist[j][1]+dist[k][2]);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

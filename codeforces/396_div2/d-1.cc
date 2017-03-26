#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,k,cnt=0;
    cin >>n>>m>>k;
    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        mp[s]=cnt++;
    }
    for(int i=0; i<m; i++) {
        int t; string a,b;
        cin >> t >> a >> b;
        int x=mp[a], y=mp[b];
        if(hasrel(x,y)) {
            if(t==1 && islike(x,y)) puts("YES");
            else if(t==2 && !islike(x,y)) puts("YES");
            else puts("NO");
        } else {

        }
    }
    return 0;
}

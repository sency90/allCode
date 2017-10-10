#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s,t;
    cin >> s;
    int n; cin >> n;
    bool chk[2];
    memset(chk,false, sizeof(chk));
    bool ans=false;
    for(int i=0; i<n; i++) {
        cin >> t;
        if(t[0]==s[1]) chk[0]=true;
        if(t[1]==s[0]) chk[1]=true;
        if(t[0]==s[0] && t[1]==s[1]) ans=true;
    }
    if(chk[0] && chk[1]) puts("YES");
    else if(ans) puts("YES");
    else puts("NO");
    return 0;


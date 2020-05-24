#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s; s+="+";
    bool f_minus = false;
    int pi=-1, ans=0;
    for(int i=0; i<s.size(); i++) {
        if(i!=0 && (s[i]=='-' || s[i]=='+')) {
            int x; sscanf(s.substr(pi+1, i-pi).c_str(), "%d", &x);
            if(f_minus) ans-=x;
            else ans+=x;
            pi = i;
        }
        if(s[i]=='-') f_minus = true;
    }
    printf("%d", ans);
    return 0;
}

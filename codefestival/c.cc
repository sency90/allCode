#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int v[100001];
int chg(char x) {
    return 26-(x-'a');
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,x;
    string s;
    cin >> s >> n;
    for(int i=0; i<s.size(); i++) {
        x=chg(s[i]);
        if(x==26) {
            v[i]=0;
        } else if(x<=n) {
            v[i]=0;
            s[i]='a';
            n-=x;
        } else v[i]=x;
        if(!n) break;
    }
    if(n) {
        int cur = 26-v[s.size()-1];
        //if(cur==26) cur=0;
        n+=cur;
        n%=26;
        s[s.size()-1]='a'+n;
    }
    printf("%s\n", s.c_str());
    return 0;
}

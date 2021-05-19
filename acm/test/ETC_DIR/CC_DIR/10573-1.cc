#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string s;
long long d[81][10][2];
long long f(int x, int prev, int t) {
    if(!prev) return 1LL;
    else if(x==-1) return t;
    long long &ret=d[x][prev][t];
    if(ret!=-1LL) return ret;
    else ret=0LL;

    for(int i=0; i<10; i++) {
        if(i<=prev) {
            if(i<s[x]-'0') ret+=f(x-1,i,true);
            else if(i==s[x]-'0') ret+=f(x-1,i,t);
            else ret+=f(x-1,i,false);
        } else continue;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        memset(d, -1, sizeof(d));
        cin >> s;
        bool hasAns=true;
        for(int i=1; s[i]; i++) {
            if(s[i-1]>s[i]) { hasAns=false; break; }
        }
        if(hasAns) printf("%lld\n",f(s.size()-1,9,true)-1);
        else puts("-1");
    }
    return 0;
}

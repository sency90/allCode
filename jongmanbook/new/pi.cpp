#include <bits/stdc++.h>
using namespace std;
string s;
int dp[10001];
const int INF = 0x3f3f3f3f;
int lp[10001][6];
int CalcLevel(const string & s, int x, int n) {
    if(n<3 || n>5) return INF;

    int & ret = lp[x][n];
    if(ret<INF) return ret;
    int cnt=0;
    for(int i=x+1; i<x+n; i++) {
        if(s[x]==s[i]) cnt++;
    }
    if(cnt==n-1) return ret=1;

    cnt=0;
    for(int i=x+1; i<x+n; i++) {
        if(s[i]-s[i-1]==1) cnt++;
    }
    if(cnt==n-1) return ret=2;

    cnt=0;
    for(int i=x+1; i<x+n; i++) {
        if(s[i]-s[i-1]==-1) cnt++;
    }
    if(cnt==n-1) return ret=2;

    cnt=0;
    int d = s[x+1]-s[x];
    for(int i=x+2; i<x+n; i++) {
        d = -d;
        if(s[i]-s[i-1] == d) cnt++;
    }
    if(cnt==n-2) return ret=4;

    cnt=0;
    d = s[x+1]-s[x];
    for(int i=x+2; i<x+n; i++) {
        if(s[i]-s[i-1] == d) cnt++;
    }
    if(cnt==n-2) return ret=5;

    return ret=10;
}
int f(int x) {
    if(x==0) return 0;
    else if(x<=2) return INF;
    int & ret = dp[x];
    if(ret>=0) return ret;

    ret=INF;
    if(x>=3) ret = min(ret, CalcLevel(s,x-2,3) + f(x-3));
    if(x>=4) ret = min(ret, CalcLevel(s,x-3,4) + f(x-4));
    if(x>=5) ret = min(ret, CalcLevel(s,x-4,5) + f(x-5));
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> s;
        s = " " + s;
        memset(dp,-1,sizeof(dp));
        memset(lp,0x3f,sizeof(lp));
        printf("%d\n", f(s.size()-1));
    }
    return 0;
}
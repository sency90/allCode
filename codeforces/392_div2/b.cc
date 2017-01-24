#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int chg(char c) {
    if(c=='R') return 1;
    else if(c=='B') return 2;
    else if(c=='Y') return 3;
    else if(c=='G') return 4;
    else return 0;
}
int cnt[101], ans[5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;

    int ansi=0;
    int n=s.size();
    for(int i=0; i<n; i+=4) cnt[chg(s[i])]++;
    for(int i=1; i<=4; i++) if(cnt[i]) ansi=i;
    ans[ansi]=cnt[0];

    memset(cnt,0,sizeof(cnt));
    ansi=0;
    for(int i=1; i<n; i+=4) cnt[chg(s[i])]++;
    for(int i=1; i<=4; i++) if(cnt[i]) ansi=i;
    ans[ansi]=cnt[0];

    memset(cnt,0,sizeof(cnt));
    ansi=0;
    for(int i=2; i<n; i+=4) cnt[chg(s[i])]++;
    for(int i=1; i<=4; i++) if(cnt[i]) ansi=i;
    ans[ansi]=cnt[0];

    memset(cnt,0,sizeof(cnt));
    ansi=0;
    for(int i=3; i<n; i+=4) cnt[chg(s[i])]++;
    for(int i=1; i<=4; i++) if(cnt[i]) ansi=i;
    ans[ansi]=cnt[0];

    for(int i=1; i<=4; i++) printf("%d ", ans[i]);

    return 0;
}

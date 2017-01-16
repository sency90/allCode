#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int cnt[7];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    int j=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='B') cnt[0]++;
        else if(s[i]=='l') cnt[1]++;
        else if(s[i]=='b') cnt[2]++;
        else if(s[i]=='s') cnt[3]++;
        else if(s[i]=='r') cnt[4]++;
        else if(s[i]=='u') cnt[5]++;
        else if(s[i]=='a') cnt[6]++;
    }
    int mn = 0x3f3f3f3f;
    for(int i=0; i<5; i++) {
        mn = min(mn, cnt[i]);
    }
    for(int i=5; i<7; i++) {
        mn = min(mn, int(cnt[i]/2));
    }
    printf("%d", mn);
    return 0;
}

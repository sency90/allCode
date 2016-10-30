#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int chg(char x, int cur) {
    int t = x-'a';
    return cur-t;
}
int chg2(char x, int cur) {
    int t = x-'a';
    return t-cur;
}
int chg3(char x, int cur) {
    int t = x-'a';
    return cur+26-t;
}
int chg4(char x, int cur) {
    int t = x-'a';
    return t+26-cur;
}
int pos(int x) {
    if(x<0) return 0x3f3f3f3f;
    else return x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int ans=0, cur=0;
    for(int i=0; i<s.size(); i++) {
        ans+=min({pos(chg(s[i],cur)),pos(chg2(s[i],cur)),pos(chg3(s[i],cur)),pos(chg4(s[i],cur))});
        cur = s[i]-'a';
    }
    printf("%d", ans);
    return 0;
}

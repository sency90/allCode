#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string t="AIOUEY";
bool isV(char x) {
    for(int i=0; i<6; i++) {
        if(x==t[i]) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int cnt=0,mx=1;
    for(int i=0; i<s.size(); i++) {
        cnt++;
        if(isV(s[i])) {
            mx=max(mx,cnt);
            cnt=0;
        }
    }
    cnt++;
    mx=max(mx,cnt);
    printf("%d\n", mx);
    return 0;
}

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int chg(char x) {
    return x-'a';
}
int po(int x) {
    if(x<0) return 0x3f3f3f3f;
    else return x;
}
int main() {
    string s;
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    int cur=0, cur2=26;
    int ans=0;
    for(int i=0; s[i]; i++) {
        int c=chg(s[i]);
        ans+=min({po(cur-c), po(c-cur), po(cur+26-c), po(c+26-cur)});
        cur=chg(s[i]);
    }
    printf("%d", ans);
    return 0;
}

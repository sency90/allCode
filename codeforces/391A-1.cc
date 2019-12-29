#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;

    int b,e=0, ans=0;
    while(e<s.size()) {
        b=e++;
        for(; e<s.size(); e++) {
            if(s[b]!=s[e]) break;
        }

        if((e-b)%2 == 0) ans++;
    }
    printf("%d\n", ans);
    return 0;
}

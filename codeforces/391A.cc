#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int cnt=1, ans=0;
    for(int i=1; i<s.size(); i++) {
        if(s[i-1]==s[i]) cnt++;
        else {
            if(cnt%2 == 0) ans++;
            cnt = 1;
        }
    }

    if(cnt%2 == 0) ans++;
    printf("%d\n", ans);
    return 0;
}

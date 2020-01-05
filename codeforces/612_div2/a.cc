#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    string s;
    while(tc--) {
        int n; cin >> n;
        cin >> s;
        bool good = false;
        int ans=0;
        do {
            good = false;
            for(int i=n-1; i>=1; i--) {
                if(s[i-1]=='A' && s[i]=='P') {
                    s[i]='A';
                    good = true;
                }
            }
            if(good) ans++;
        } while(good);
        printf("%d\n", ans);
    }
    return 0;
}

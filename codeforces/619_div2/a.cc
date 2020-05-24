#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    string a,b,c;
    while(tc--) {
        cin >> a >> b >> c;
        if(a.size() != b.size() || b.size() != c.size() || c.size() != a.size()) {
            puts("NO");
            continue;
        }
        bool good = true;
        for(int i=0; i<a.size(); i++) {
            if(a[i]==c[i] || b[i]==c[i]) continue;
            else {
                good = false;
                break;
            }
        }
        if(good) puts("YES");
        else puts("NO");
    }
    return 0;
}

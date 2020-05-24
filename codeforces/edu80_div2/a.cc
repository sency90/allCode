#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int ceiling(int d, int k) {
    if(d%k == 0) return d/k;
    else return d/k+1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n,d; cin >> n >> d;
        if(d<=n) puts("YES");
        else {
            int x = n/2-50;
            if(x<0) x=0;

            bool good = false;
            int y = n/2+50;
            if(y>n) y=n;
            for(int i=x; i<=y; i++) {
                if(i+ceiling(d,(i+1)) <= n) {
                    good = true;
                    break;
                }
            }

            if(good) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}

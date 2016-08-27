#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a[4];
    for(int i=0; i<4; i++) {
        cin >> a[i];
    }
    if(a[1]!=a[2] || a[0]>=2 || a[3]>=2 || a[1]>2 || a[2]>2) {
        cout << "Impossible";
        return 0;
    } else {
        if(a[0]==1) {
            ans="00";
            if(a[1]==0) {
                if(a[3]==0) {
                    cout << ans;
                    return 0;
                } else {
                    cout << "Impossible";
                    return 0;
                }
            } else if(a[1]==1) {
                ans+="1";
                if(a[3]==0) {
                    cout << ans;
                    return 0;
                } else {
                    ans+="1";
                    cout << ans;
                    return 0;
                }
            } else if(a[1]==2) {
                ans+="10";
                if(a[3]==0) {
                    cout << ans;
                    return 0;
                } else {
                    ans+="1";
                    cout << ans;
                    return 0;
                }
            }
        } else {
            ans="0";
            if(a[1]==0) {
                if(a[3]==0) {
                    cout << ans;
                    return 0;
                } else {
                    cout << "Impossible";
                    return 0;
                }
            } else if(a[1]==1) {
                ans += "1";
                if(a[3]==0) {
                    cout << ans;
                    return 0;
                } else {
                    ans += "1";
                    cout << ans;
                    return 0;
                }
            } else if(a[1]==2) {
                ans += "10";
                if(a[3]==0) {
                    cout << ans;
                    return 0;
                } else {
                    ans+="1";
                    cout << ans;
                    return 0;
                }
            }
        }
    }
    return 0;
}

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s,c="christmas";
    cin >> s;
    int n=c.size(), cnt=0;
    for(int i=0,j=0; j<s.size(); j++) {
        if(s[j]==c[i]) {
            if(++i==n) {
                i%=n;
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}

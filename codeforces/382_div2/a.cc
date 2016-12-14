#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool start=false,end=false;
    for(int i=0; i<n; i++) {
        if(s[i]=='G'||s[i]=='T') {
            if(!start) {
                start=true;
                i+=k-1;
            } else {
                end=true;
                break;
            }
        }
        else if(start) {
            if(s[i]=='#') {
                end=false;
                break;
            } else {
                i+=k-1;
            }
        }
    }
    if(!end) puts("NO");
    else puts("YES");
    return 0;
}

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
string s, rs;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    int b=0, e=s.size()-1;
    while(b<=e) {
        bool left = false;
        for(int i=0; b+i<=e; i++) {
            if(s[b+i]<s[e-i]) {
                left=true;
                break;
            } else if(s[b+i]>s[e-i]) {
                left=false;
                break;
            }
        }
        if(left) putchar(s[b++]);
        else putchar(s[e--]);
    }
    return 0;
}

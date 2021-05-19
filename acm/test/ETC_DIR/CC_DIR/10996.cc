#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    if(n==1) return 0&puts("*");

    string s[2];
    for(int i=0; i<n; i++) {
        if(i%2==0) {
            s[0]+="*";
            s[1]+=" ";
        }
        else {
            s[0]+=" ";
            s[1]+="*";
        }
    }
    for(int i=0; i<n; i++) {
        printf("%s\n", s[0].c_str());
        printf("%s\n", s[1].c_str());
    }
    return 0;
}

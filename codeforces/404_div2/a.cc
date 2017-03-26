#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    string s;
    ll sum=0ll;
    for(int i=0; i<n; i++) {
        cin >> s;
        if(s[0]=='T') sum+=4;
        else if(s[0]=='C') sum+=6;
        else if(s[0]=='O') sum+=8;
        else if(s[0]=='D') sum+=12;
        else if(s[0]=='I') sum+=20;
    }
    printf("%lld\n", sum);
    return 0;
}

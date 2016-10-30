#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int p[27],p1,p2;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    memset(p, -1, sizeof(p));
    for(int i=0; i<27; i++) {
        int c = s[i]-'A';
        if(p[c]==-1) p[c]=i;
        else {
            p1=p[c];
            p2=i;
            break;
        }
    }
    if(p1+1 == p2) {
        puts("Impossible");
        return 0;
    }
    s = s.substr(0,p2)+s.substr(p2+1);
    int shift = (p1+p2+1)/2;
    s = s.substr(shift)+s.substr(0, shift);
    cout << s.substr(0,13) << "\n";
    reverse(s.begin(), s.end());
    cout << s.substr(0,13) << "\n";
    return 0;
}

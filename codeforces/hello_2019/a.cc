#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s, card[5];
    cin >> s;
    bool good = false;
    for(int i=0; i<5; i++) {
        cin >> card[i];
        if(s[0]==card[i][0]) {
            good = true;
            puts("YES");
            break;
        }
        else if(s[1]==card[i][1]) {
            good = true;
            puts("YES");
            break;
        }
    }
    if(!good) puts("NO");
    return 0;
}

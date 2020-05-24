#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int l=0, r=0;
    for(int i=0; i<n; i++) {
        if(s[i]=='L') l--;
        else if(s[i]=='R') r++;
    }

    printf("%d\n", r-l+1);
    return 0;
}

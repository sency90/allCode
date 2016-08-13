#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
string s, ps;
int c[100000];
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> c[i];
    }

    cin >> ps;
    for(int i=1; i<n; i++) {
        cin >> s;
        sort(s.begin(), s.end());
        ps = s;
    }

    return 0;
}

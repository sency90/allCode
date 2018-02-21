#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("input.txt", "r", stdin);
    while(getline(cin, s)) {
        s = "cp Makefile "+ s;
        //printf("%s\n", s.c_str());
        system(s.c_str());
    }
    return 0;
}

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    int cnt=0;
    while(cin >> s) {
        cnt++;
    }
    printf("%d\n", cnt);
}

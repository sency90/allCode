#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    cout << s.substr(0,4) << " " << s.substr(4,8) <<"\n";
    return 0;
}

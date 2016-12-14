#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;
set<string> s;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("/Users/lian/Downloads/groceries.csv", "r", stdin);
    freopen("./output.txt", "w", stdout);
    string token, str;
    while(getline(cin,str)) {
        istringstream iss(str);
        while(getline(iss,token,',')) {
            s.insert(token);
        }
    }
    int cnt=0;
    for(auto &p: s) {
        cout << ++cnt << p << "\n";
    }
    return 0;
}

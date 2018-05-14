#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cctype>
using namespace std;
void trimLeft(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch){ return !isspace(ch); }));
}
void trimRight(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch){ return !isspace(ch); }).base(), s.end());
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s = "\n\t            hi my name is lian.   \t \n";
    trimLeft(s);
    auto it = find_if(s.rbegin(), s.rend(), [](int ch){
            return !isspace(ch);
            }).base();
    //cout << s << "\n";
    cout << it-s.begin();
    return 0;
}

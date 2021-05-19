#include <cstdio>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
string line;
inline bool isOpen(char c) { return c=='(' || c=='['; }
inline bool isClose(char c) { return c==')' || c==']'; }
char findPair(char c) {
    if(c=='(') return ')';
    else if(c==')') return '(';
    else if(c=='[') return ']';
    else if(c==']') return '[';
    return '.'; //err
}
stack<char> s;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    while(getline(cin, line)) {
        if(!line.empty() && line[0]=='.') return 0;
        bool good = true;
        for(int i=0; i<line.size(); i++) {
            if(isOpen(line[i])||isClose(line[i])) {
                if(isOpen(line[i])) s.push(line[i]);
                else if(isClose(line[i])) {
                    if(s.empty()) {
                        good = false;
                        break;
                    }
                    else {
                        char c = s.top(); s.pop();
                        if(findPair(c) != line[i]) {
                            good = false;
                            break;
                        }
                    }
                }
            }
        }
        if(good && s.empty()) puts("yes");
        else puts("no");
        while(!s.empty()) s.pop();
    }
    return 0;
}

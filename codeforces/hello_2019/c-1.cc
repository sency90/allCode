#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
string s;
stack<int> stk;
int main() {
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            if(s[j]=='(') {
                stk.push(0);
            } else {
                if(stk.empty() || stk.top()==1) stk.push(1);
                else stk.pop();
            }
            while(!stk.empty()) {
                int x = stk.top(); stk.pop();

            }
        }
    }
    return 0;
}

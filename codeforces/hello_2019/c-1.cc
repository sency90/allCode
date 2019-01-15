#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
string s;
stack<int> stk;
int dic[2][500001];
int main() {
    int n; cin >> n;
    int ans=0, perfect=0;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            if(s[j]=='(') {
                stk.push(0);
            } else {
                if(stk.empty() || stk.top()==1) stk.push(1);
                else stk.pop();
            }
        }
        int flag = 0, one=0, zero=0;
        while(!stk.empty()) {
            int x = stk.top(); stk.pop();
            if(x) flag |= 1, one++;
            else flag |=2, zero++;
        }
        if(flag==3) continue;

        if(one) {
            if(dic[0][one]>0) dic[0][one]--, ans++;
            else dic[1][one]++;
        } else if(zero) {
            if(dic[1][zero]>0) dic[1][zero]--, ans++;
            else dic[0][zero]++;
        } else {
            if(perfect) ans++;
            perfect^=1;
        }
    }
    printf("%d", ans);
    return 0;
}

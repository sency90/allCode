#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;
stack<int> stk;
void isValid(string &s, string &r) {
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') {
            stk.push(1);
        } else {
            if(!stk.empty() && stk.top()==1) stk.pop();
            else stk.push(0);
        }
    }
    int hasBoth=0;
    s=""; r="";
    while(!stk.empty()) {
        int top = stk.top(); stk.pop();
        if(top==0) {
            s = s + ")";
            r = r + "(";
            hasBoth|=1;
        }
        else {
            s = s + "(";
            r = r + ")";
            hasBoth|=2;
        }
    }
    if(hasBoth == 3) s="!";
}
map<string,int> mp;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s,r;
    int n; cin >> n;
    int cnt=0;
    for(int i=0; i<n; i++) {
        cin >> s;
        isValid(s,r);
        if(s=="!") continue;
        if(mp.count(r)>0) {
            cnt++;
            if(--mp[r] == 0) mp.erase(r);
        } else {
            mp[s]++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

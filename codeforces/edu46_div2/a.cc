#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map<string, int> mp;
string t[101];
bool good[101];
bool isValid(const string &s) {
    int n = s.size();
    if(n==1) {
        if(s[0]=='M' || s[0]=='L' || s[0]=='S') return true;
        else return false;
    } else {
        if(n>4) return false;
        for(int i=0; i<n-1; i++) {
            if(s[i]!='X') return false;
        }
        if(s[n-1]=='S' || s[n-1]=='L') return true;
        else return false;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> t[i];
        if(isValid(t[i])) mp[t[i]]++;
    }
    int ans=0;
    for(int i=0; i<n; i++) {
        cin >> t[i];
        if(isValid(t[i])) mp[t[i]]--;
    }
    for(auto &it : mp) if(it.second>0) ans+=it.second;
    printf("%d", ans);
    return 0;
}

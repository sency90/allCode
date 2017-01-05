#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
void f(int n, const string &s, string &ans) {
    if(n==0) return;
    if(n%2==1) {
        ans+=s[0];
        f(n-1, s.substr(1,n),ans);
    } else {
        ans=s[0]+ans;
        f(n-1, s.substr(1,n),ans);
    }
}
int main() {
    string s,ans;
    int n;
    cin >> n >> s;
    f(n,s,ans);
    cout << ans;
    return 0;
}

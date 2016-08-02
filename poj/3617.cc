#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n;
    char c;
    string s, rs;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> c;
        s+=c;
    }
    n--;
    int l=0, r=s.size()-1, cnt=0;
    while(l<r) {
        if(s[l]<s[r]) cout << s[l++];
        else if(s[l]>s[r]) cout << s[r--];
        else {
            string s2 = s.substr(l,r-l+1);
            string s1 = s2;
            reverse(s2.begin(), s2.end());
            if(s1<s2) cout << s[l++];
            else cout << s[r--];
        }
        if(++cnt==80) {
            cnt=0;
            puts("");
        }
    }
    if(l==r) cout << s[l];
    return 0;
}

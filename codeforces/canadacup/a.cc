#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    int n;
    cin >> n >> s;
    int cnt1=0, cnt2=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='<') cnt1++;
        else break;
    }
    for(int i=s.size()-1; i>=0; i--) {
        if(s[i]=='>') cnt2++;
        else break;
    }
    printf("%d\n",cnt1+cnt2);
    return 0;
}

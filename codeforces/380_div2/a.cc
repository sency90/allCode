#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; string s,ans;
    cin >> n >> s;
    bool hasAns=false;
    for(int i=0; i<n;) {
        if(s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o') {
            ans+="***";
            hasAns=true;
            i+=3;
        } else if(hasAns&&s[i]=='g'&&s[i+1]=='o') {
            i+=2;
        } else {
            ans+=s[i];
            hasAns=false;
            i++;
        }
    }
    cout << ans;
    return 0;
}

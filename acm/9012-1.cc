#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<int> s;
int main() {
    ios::sync_with_stdio(false);
    int tc; cin>>tc;
    string str;
    while(tc--) {
        int cnt=0;
        cin >> str;
        for(int i=0; i<str.size(); i++) {
            if(str[i]=='(') cnt++;
            else cnt--;
            if(cnt<0) break;
        }
        if(cnt==0) puts("YES");
        else puts("NO");
    }
    return 0;
}

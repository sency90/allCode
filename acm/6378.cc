#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    while(cin>>s) {
        if(s=="0") break;
        int tmp=0;
        while(true) {
            for(int i=0; i<s.size(); i++) {
                tmp += (s[i]-'0');
            }
            if(tmp>=10) {
                s=to_string(tmp);
                tmp=0;
            } else break;
        }
        printf("%d\n", tmp);
    }
    return 0;
}

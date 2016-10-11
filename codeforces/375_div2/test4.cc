#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int m,t,now,q,i;
int main() {
    int n;
    string s;
    cin>>n>>s;
    while(i<n) {
        if(s[i]=='(') {
            m=max(m,now);
            now=0;
            q=0;
            while(s[i]!=')') {
                i++;
                if(s[i]==')') break;
                if(s[i]=='_') {
                    if(q) t++;
                    q=0;
                } else {
                    q++;
                }
            }
            if(q) t++;
        }
        else if(s[i]=='_') {
            m=max(m,now);
            now=0;
        } else {
            now++;
        }
        i++;
    }
    if(now) m= max(m,now);
    cout << m << ' ' << t;
    return 0;
}

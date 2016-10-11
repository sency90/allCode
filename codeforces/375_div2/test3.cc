#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int main() {
    int n;
    string s;
    cin>>n>>s;
    ++n;
    s+='_';
    int res1=0, res2=0;
    int cur_len=0;
    bool parens =false;
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='(') {
            parens = true;
            if(cur_len>0) {
                res1=max(res1,cur_len);
                cur_len=0;
            }
        } else if(s[i]==')') {
            parens=false;
            if(cur_len>0) {
                res2++;
                cur_len=0;
            }
        } else if(s[i]=='_') {
            if(cur_len>0) {
                if(!parens) res1=max(res1, cur_len);
                else res2++;
                cur_len=0;
            }
        } else {
            cur_len++;
        }
    }
    cout<<res1<<" "<<res2<<endl;
    return 0;
}

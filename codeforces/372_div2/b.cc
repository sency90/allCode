#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
int chg(char x) {
    if(x=='?') return 26;
    else return x-'A';
}
int cnt[27];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    bool hasAns=false;
    for(int i=0; i<s.size(); i++) {
        bool isBrk = false;
        int sum=0;
        for(int j=i; j<s.size() && j<i+26; j++) {
            sum++;
            int z=chg(s[j]);
            if(++cnt[z]==2 && z!=26) {
                memset(cnt,0,sizeof(cnt));
                isBrk=true;
                break;
            }
        }
        if(!isBrk && sum==26) {
            hasAns=true;
            for(int j=i; j<i+26; j++) {
                if(s[j]=='?') {
                    for(int k=0; k<26; k++) {
                        if(cnt[k]==0) {
                            s[j]=k+'A';
                            cnt[k]++;
                            break;
                        }
                    }
                }
            }
            break;
        }
    }
    if(!hasAns) puts("-1");
    else {
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='?') s[i]='A';
        }
        printf("%s\n", s.c_str());
    }
    return 0;
}

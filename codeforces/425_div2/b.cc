#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
string s, c, p;
bool chk[26];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s >> c;
    for(int i=0; i<s.size(); i++) {
        chk[s[i]-'a']=true;
    }
    int pos=-1;
    for(int j=0; j<c.size(); j++) {
        if(c[j]=='*') { pos=j; break; }
    }

    int n; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> p;
        bool hasAns=true;
        if(pos>=0) {
            if(p.size()<pos) hasAns=false;
            else {
                for(int j=0; j<pos; j++) {
                    if(c[j]=='?') {
                        if(chk[p[j]-'a']) continue;
                        else { hasAns=false; break; }
                    } else if(c[j]!=p[j]) { hasAns=false; break; }
                }
            }

            int rpos=p.size()-1;
            for(int j=c.size()-1, k=p.size()-1; j>pos; j--,k--) {
                rpos=k;
                if(k<pos) { hasAns=false; break; }
                if(c[j]=='?') {
                    if(chk[p[k]-'a']) continue;
                    else { hasAns=false; break; }
                } else if(c[j]!=p[k]) { hasAns=false; break; }
            }

            if(hasAns) {
                for(int j=pos; j<rpos; j++) {
                    if(chk[p[j]-'a']) { hasAns=false; break; }
                }
            }
        } else {
            if(p.size()!=c.size()) hasAns=false;
            else {
                for(int j=0; j<p.size(); j++) {
                    if(c[j]=='?') {
                        if(chk[p[j]-'a']) continue;
                        else { hasAns=false; break; }
                    } else if(c[j]!=p[j]) { hasAns=false; break; }
                }
            }
        }
        if(hasAns) puts("YES");
        else puts("NO");
    }
    return 0;
}

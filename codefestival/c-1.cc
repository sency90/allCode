#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
int v[100001];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    int n;
    cin >> s >> n;
    for(int i=0; i<s.size(); i++) {
        v[i]=26-(s[i]-'a');
        if(v[i]==26) { v[i]=0; continue; }
        if(v[i]<=n) { n-=v[i]; v[i]=0; }
        if(!n) break;
    }
    bool allzero=true;
    if(n>=26) n%=26;
    for(int i=0; i<s.size(); i++) {
        if(v[i]!=0) {
            allzero=false;
            break;
        }
    }
    if(!allzero) {
        for(int i=s.size()-1; i>=0; i--) {
            if(n) {
                if(v[i]) v[i]=26-v[i];
                v[i]+=n;
                n=0;
                continue;
            }
            if(!v[i]) continue;
            else v[i]=26-v[i];
        }
    } else {
        v[s.size()-1]+=n;
    }
    for(int i=0; i<s.size(); i++) {
        putchar(v[i]+'a');
    }
    puts("");
    return 0;
}

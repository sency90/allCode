#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
vector<string> v,hs;
string s;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s;
        v.emplace_back(s);
    }
    if(v.size()<16) {
        for(int i=0; i<16; i++) {
            for(int j=0; j<n; j++) {
                v.emplace_back(v[j]);
                if(v.size()==16) goto OUT;
            }
        }
    }
OUT:
    for(int i=0; i<25; i++) {
        hs.emplace_back(string("Happy"));
        hs.emplace_back(string("birthday"));
        hs.emplace_back(string("to"));
        if(i%4!=2) hs.emplace_back(string("you"));
        else hs.emplace_back(string("Rujia"));
    }
    int lim = (v.size()+15)/16*16;
    for(int i=0; i<n; i++) v.emplace_back(v[i]);
    for(int i=0; i<lim; i++) {
        printf("%s: %s\n", v[i].c_str(), hs[i].c_str());
    }
    return 0;
}

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
string s,r,in;
map<char,int> mp;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    cin >> r;
    cin >> in;
    for(int i=0; i<s.size(); i++) {
        mp[s[i]]=i;
    }
    for(int i=0; i<in.size(); i++) {
        bool isCap=false;
        if(isdigit(in[i])) {
            putchar(in[i]);
            continue;
        }
        else if(isupper(in[i])) {
            in[i]=in[i]-'A'+'a';
            isCap=true;
        }
        if(isCap) putchar(r[mp[in[i]]]-'a'+'A');
        else putchar(r[mp[in[i]]]);
    }
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
string s;
bool contain(string &s, string &a) {
    int cnt=0;
    for(int i=0,j=0; i<s.size(); i++) {
        if(s[i]==a[j++]) cnt++;
        else j=0,cnt=0;
        if(cnt==4) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s,x="Hajj";
    for(int z=1;;z++) {
        cin >> s;
        if(s=="*") return 0;
        if(contain(s,x)) printf("Case %d: Hajj-e-Akbar\n",z);
        else printf("Case %d: Hajj-e-Asghar\n",z);
    }
    return 0;
}

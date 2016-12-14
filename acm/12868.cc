#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string aaa="aaaaaaaaaaaaaaaaaaaaaaaaa";
string f(int v, string s, string ns) {
    if(v==0&&s.size()==0) return ns;
    for(int i=0; i<ns.size(); i++) {
        if(s[0]>ns[i]) continue;
        int nv = max(v-i,0);
        int nn = ns.size()-1;
        if(nn*(nn-1)/2>=nv) {
            char c=ns[i];
            ns=ns.substr(0,i)+ns.substr(i+1);
            if(c==s[0]) return c+f(nv,s.substr(1),ns);
            else return c+f(nv,aaa.substr(0,nn),ns);
        }
    }
    return "";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,v;
    string s,ns;
    cin>>n>>v>>s;
    for(int i=0; i<n; i++) {
        ns+='a'+i;
    }
    cout << f(v,s,ns) << "\n";
}

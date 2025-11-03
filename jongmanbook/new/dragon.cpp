#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
//[s,e]
string f(int gen, ll s, const string & str, int qs, int qe) {
    if(gen==N) {
        if(qs>=s) return str.substr(qs-s,qe-qs+1);
        else return str.substr(0,qe-s+1);
    }
    string ret;
    for(int i = 0; i < str.size(); i++) {
        if(str[i]=='X') {
            ll e = s + 3*(1LL<<(N-gen))-3;
            if(!(e<qs || qe<s)) ret += f(gen+1,s,"X+YF",qs,qe);
            s = e+1;
        }
        else if(str[i]=='Y') {
            ll e = s + 3*(1LL<<(N-gen))-3;
            if(!(e<qs || qe<s)) ret += f(gen+1,s,"FX-Y",qs,qe);
            s = e+1;
        }
        else {
            ll e = s;
            if(!(e<qs || qe<s)) ret += string(1,str[i]);
            s = e+1;
        }
        if(s>qe) break;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        ll n,p,l; cin >> n >> p >> l;
        N = n;
        printf("%s\n", f(0,0,"FX",p-1,p-1+l-1).c_str());
    }
    return 0;
}
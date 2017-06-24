#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7LL;
string sfx=".in", ifname, ofname, s;
int main() {
    ios::sync_with_stdio(false);
    for(int z=1; z<=50; z++) {
        if(z<10) {
            ifname=string("data")+'0'+to_string(z)+sfx;
            ofname=string("data")+'0'+to_string(z)+string(".out");
        } else {
            ifname=string("data")+to_string(z)+sfx;
            ofname=string("data")+to_string(z)+string(".out");
        }
        ifstream in(ifname);
        ofstream out(ofname);
        in.tie(0);
        out.tie(0);

        int n,k;
        ll x,ans=0LL;
        in >> n;
        for(int i=0; i<n; i++) {
            in >> x >> k;
            for(ll mul=1LL; k; mul*=x, k>>=1) {
                if(mul>=mod) mul%=mod;
                if(k&1) {
                    ans+=mul;
                    if(ans>=mod) ans%=mod;
                }
            }
        }
        out << ans;
    }
    return 0;
}

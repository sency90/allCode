#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ll;
int main() {
    freopen("./input.txt","r",stdin);
    freopen("output_large_a.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    int tc; cin >> tc;
    ll l,r;
    for(int z=1; z<=tc; z++) {
        cin >> s >> l >> r;
        l--; r--;
        ll cnt=0LL;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='B') cnt++;
        }
        int rend=r/(ll)s.size(), lend=l/(ll)s.size();
        if(lend==rend) {
            cnt=0LL;
            l%=(ll)s.size();
            r%=(ll)s.size();
            for(ll i=l; i<=r; i++) {
                if(s[i]=='B') cnt++;
            }
            printf("Case #%d: %lld\n", z,cnt);
        } else if(lend+1==rend) {
            cnt=0LL;
            int ss = l%(ll)s.size(), ee=r%(ll)s.size();
            for(int i=ss; i<s.size(); i++) if(s[i]=='B') cnt++;
            for(int i=0; i<=ee; i++) if(s[i]=='B') cnt++;
            printf("Case #%d: %lld\n", z,cnt);
        } else {
            cnt*=(ll)(rend-lend-1);
            int ss = l%(ll)s.size(), ee=r%(ll)s.size();
            for(int i=ss; i<s.size(); i++) if(s[i]=='B') cnt++;
            for(int i=0; i<=ee; i++) if(s[i]=='B') cnt++;
            printf("Case #%d: %lld\n", z,cnt);
        }
    }
    return 0;
}

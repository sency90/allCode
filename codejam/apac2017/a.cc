#include <cstdio>
#include <iostream>
using namespace std;
const int lim = 1e6+5;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("./input.txt","r",stdin);
    freopen("output_a.txt","w",stdout);
    int tc;
    cin >> tc;
    for(int z=1; z<=tc; z++) {
        string s;
        cin >> s;
        for(int i=0; s.size()<=lim; i++) {
            s+=s;
        }
        int l,r;
        cin >> l >> r;
        l--; r--;
        int cnt=0;
        for(int i=l; i<=r; i++) {
            if(s[i]=='B') cnt++;
        }
        printf("Case #%d: %d\n", z,cnt);
    }
    return 0;
}

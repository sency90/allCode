#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
string line;
vector<int> v[26];
bool chk[26];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,x; cin >> n;
    cin >> line;
    for(int i=0; i<line.size(); i++) {
        x = line[i]-'a';
        if(v[x].size()==0) {
            v[x].push_back(i);
            v[x].push_back(i);
        }
        else if(v[x].size()==2){
            if(v[x][1]==i-1) v[x][1] = i;
            else {
                v[x].push_back(i);
                v[x].push_back(i);
            }
        } else if(v[x].size()==4){
            if(v[x][3]==i-1) v[x][3] = i;
            else v[x][2] = v[x][3] = i;
        }
    }
    for(int i=0; i<26; i++) {
        for(int j=0; j<v[i].size(); j++) {
            v[i][j]++;
        }
    }
    ll ans=0LL, l, r;
    for(int i=0; i<26; i++) {
        if(v[i].size()==0) continue;
        if(v[i][0]==1) l = v[i][1]+1;
        else l = 1;

        if(v[i].size()==2) {
            if(v[i][1]==n) r = v[i][0]-1;
            else r=n;
        } else {
            if(v[i][3]==n) r = v[i][2]-1;
            else r=n;
        }

        ans += l*(n-r+1)-1;
        ans %= mod;
    }
    ans++;
    ans%=mod;
    printf("%lld\n", ans);
    return 0;
}

#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;
map<string, int> mp;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, cnt=0; string s,c;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s >> c;
        if(c=="+") mp[s]++;
        else {
            if(mp[s]==0) cnt++;
            else mp[s]--;
        }
    }
    for(auto &p: mp) cnt+=p.second;
    cout << cnt;
    return 0;
}

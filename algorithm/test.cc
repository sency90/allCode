#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
int hashing(string &s, int h) {
    ll ret=0, mul=1;
    for(int i=0; i<s.size(); i++) {
        ret+=s[i]*mul;
        ret%=mod;

        mul*=h;
        mul%=mod;
    }
    return ret;
}
int main() {
    string s;
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    cout << hashing(s,31);
    return 0;
}

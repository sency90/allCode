#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int chg(char x) {
    if(isupper(x)) return x-'A'+27;
    else return x-'a'+1;
}
vector<int> getsfx(const string &s) {
    int n = s.size();
    vector<int> sfx(n), g(n+1), ng(n+1);
    for(int i=0; i<n; i++) {
        sfx[i]=i;
        g[i]=chg(s[i]);
    }
    int lim = max(n,)
    for(int i=0; i<n; i++) cnt[g(min(i+t,n))]++;
    for(int i=1; i<lim)
    return sfx;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    vector<int> sfx = getsfx(s);
    return 0;
}

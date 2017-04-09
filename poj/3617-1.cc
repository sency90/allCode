#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; string s;
    cin >> n >> s;

    string rs=s, ans;
    reverse(rs.begin(), rs.end());
    for(int o=0, ro=0; o+ro<n;) {
        int cmp = s.compare(o,s.size()-o, rs,ro,rs.size()-ro);
        if(cmp<=0) ans+=s[o++];
        else ans+=s[ro++];
    }
    printf("%s\n", ans.c_str());
    return 0;
}

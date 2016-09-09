#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> getPartialTable(const string &N) {
    int n=N.size(), matched=0;
    vector<int> pi(n, 0);
    for(int i=1; i<n; i++) {
        while(matched!=0 && N[i]!=N[matched]) matched = pi[matched-1];
        if(N[i]==N[matched]) pi[i]=++matched;
    }
    return pi;
}
int kmp(const string &H, const string &N) {
    vector<int> pi = getPartialTable(N);
    int matched=0;
    for(int i=0; i<H.size(); i++) {
        while(matched!=0 && H[i]!=N[matched]) matched=pi[matched-1];
        if(H[i]==N[matched]) matched++;
    }
    return (H.size()<<1)-matched;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc; cin >> tc;
    string s, rs;
    while(tc--) {
        cin >> s;
        rs=s; reverse(rs.begin(), rs.end());
        cout << kmp(s, rs) << "\n";
    }
    return 0;
}

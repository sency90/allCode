#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> partialTable(const string &N) {
    vector<int> pi(N.size(), 0);
    int matched = 0;
    for(int i=1; i<N.size(); i++) {
        while(matched!=0 && N[i]!=N[matched]) matched = pi[matched-1];
        if(N[i]==N[matched]) {
            matched++;
            pi[i]=matched;
        }
    }
    return pi;
}
vector<int> kmp_short(const string &H, const string &N) {
    vector<int> ret, pi = partialTable(N);
    int matched = 0;
    for(int i=0; i<H.size(); i++) {
        while(matched!=0 && H[i]!=N[matched]) matched = pi[matched-1];
        if(H[i]==N[matched]) {
            matched++;
            if(matched == N.size()) {
                ret.push_back(i-(matched-1)+1);
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string H, N;
    getline(cin, H);
    getline(cin, N);
    vector<int> ans = kmp_short(H, N);
    cout << ans.size() <<"\n";
    for(auto &p : ans) {
        cout << p << " ";
    }
    return 0;
}

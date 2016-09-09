#include <string>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> kmp(const string &H, const string &N) {
    vector<int> pi(N.size(), 0);
    int begin=1, matched=0;
    while(begin+matched<N.size()) {
        if(N[begin+matched] == N[matched]) {
            matched++;
            pi[begin+matched-1] = matched;
        } else {
            if(matched==0) begin++;
            else {
                begin += matched-pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }

    vector<int> ret;
    begin=0; matched=0;
    while(begin+matched<H.size()) {
        if(matched<N.size() && H[begin+matched] == N[matched]) {
            matched++;
            if(matched==N.size()) ret.push_back(begin+1);
        } else {
            if(matched==0) begin++;
            else {
                begin += matched-pi[matched-1];
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
    vector<int> ans = kmp(H,N);
    cout << ans.size() << "\n";
    for(auto &p : ans) {
        cout << p <<" ";
    }
    return 0;
}

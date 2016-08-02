#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string H, N;
vector<int> getPartialTable() {
    vector<int> pi(N.size(), 0);
    int begin=1, matched=0;
    while(begin+matched <= N.size()) {
        if(N[matched] == N[begin+matched]) {
            matched++;
            pi[begin+matched-1] = matched;
        } else {
            if(matched == 0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}
int kmp() {
    int begin=0, matched=1;
    vector<int> pi = getPartialTable();
    while(begin+matched <= N.size()) {
        if(H[begin+matched] == N[matched]) {
            matched++;
            if(begin+matched == N.size()) return 2*N.size()-matched;
        } else {
            if(matched == 0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return 2*N.size();
}
int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> H;
        N = H; reverse(N.begin(), N.end());
        cout << kmp() << "\n";
    }
    return 0;
}

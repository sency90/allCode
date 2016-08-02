#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> getPartialTable(const string &N) {
    int begin=1, matched=0, m=N.size();
    vector<int> pi(m, 0);
    while(begin+matched < m) {
        if(N[begin+matched] == N[matched]) {
            ++matched;
            pi[begin+matched-1]=matched;
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
vector<int> kmp(const string &H, const string &N) {
    vector<int> ret;
    int n=H.size(), m=N.size();
    int begin=0, matched=0;
    vector<int> pi = getPartialTable(N);
    while(begin <= n-m) {
        if(matched<m && H[begin+matched] == N[matched]) {
            if(++matched == m) ret.push_back(begin);
        } else {
            if(matched == 0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    string H, N;
    cin >> H >> N;
    vector<int> ans = kmp(H, N);
    for(auto &p : ans) {
        cout << p << " " << H.c_str()+p <<"\n";
    }
    return 0;
}

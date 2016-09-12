#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> getPartialTable(const string &N) {
    vector<int> pi(N.size(), 0);
    int begin=1, matched=0;
    while(begin+matched<N.size()) {
        if(N[begin+matched] == N[matched]) {
            matched++;
            pi[begin+matched-1] = matched;
        } else {
            if(matched==0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}
vector<int> kmp(const string &H, const string &N) {
    vector<int> ret, pi = getPartialTable(N);
    int begin=0, matched=0;
    while(begin+matched<H.size()) {
        if(matched<N.size() && H[begin+matched] == N[matched]) {
            if(++matched == N.size()) ret.push_back(begin);
        } else {
            if(matched==0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}
int main() {
    string H, N;
    ios::sync_with_stdio(false); cin.tie(0);
    getline(cin, H);
    getline(cin, N);
    vector<int> ans = kmp(H, N);
    return 0;
}

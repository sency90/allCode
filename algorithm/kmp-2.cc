#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
vector<int> getPartialTable(const string &N) {
    vector<int> pi(N.size(), 0);
    int begin=1, matched=0, n=N.size();
    while(begin+matched<n) {
        if(N[begin+matched]==N[matched]) {
            matched++;
            pi[begin+matched] = matched;
        } else {
            if(matched==0) begin++;
            else {
                begin += matched-pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}
vector<int> kmp(const string &H, const string &N) {
    int h=H.size(), n=N.size();
    vector<int> pi = getPartialTable(N);
    vector<int> ret;
    int begin=0, matched=0;
    while(begin+matched<h) {
        if(H[begin+matched] == N[matched]) {
            matched++;
            if(matched==n) ret.push_back(begin);
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
    cin >> H >> N;
    vector<int> ans = kmp(H, N);
    for(auto &p : ans) {
        for(int i=0; i<p; i++) {
            cout << " ";
        }
        cout << H.substr(p,N.size()) << "\n";
    }
    return 0;
}

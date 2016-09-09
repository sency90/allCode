#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
vector<int> getPartialTable(const string &N) {
    int m = N.size();
    int begin=1, matched=0;
    vector<int> pi(m, 0);
    while(begin+matched <= m) {
        if(N[begin+matched] == N[matched]) {
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
int kmp(const string &H, const string &N) {
    int n = H.size(), m = N.size();
    int begin=1, matched=0;
    vector<int> pi = getPartialTable(N);
    while(begin+m <= n) {
        if(matched<m && H[begin+matched]==N[matched]) {
            if(++matched == m) return begin;
        } else {
            if(matched == 0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return begin;
}
int shifts(const string &H, const string &N, bool cw) {
    if(cw) return kmp(H+H, N);
    else return kmp(N+N, H);
}
int main() {
    ios::sync_with_stdio(false);
    int tc,n;
    string H, N;
    cin >> tc;
    while(tc--) {
        int ans = 0;
        cin >> n;
        cin >> N;
        for(int i=1; i<=n; i++) {
            cin >> H;
            ans+=shifts(H, N, i&1);
            N = H;
        }
        cout << ans << "\n";
    }
    return 0;
}

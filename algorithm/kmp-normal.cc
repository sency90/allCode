#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> getPartialTable(const string &N) {
    int m = N.size();
    int begin=1, matched=0;
    vector<int> pi(m, 0);
    while(begin+matched <= m) {
        if(N[matched] == N[begin+matched]) {
            matched++;
            pi[begin+matched-1] = matched;
        } else {
            if(matched == 0) begin++;
            else {
                begin += matched-pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}
vector<int> kmp(const string &H, const string &N) {
    vector<int> ret;
    vector<int> pi = getPartialTable(N);
    for(auto &p: pi) printf("%d ", p);
    puts("");
    int n=H.size(), m=N.size();
    int begin=0, matched=0;
    while(begin+m <= n) {
        if(H[begin+matched] == N[matched]) {
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
    for(auto &p: ans) {
        for(int i=0; i<p; i++) putchar(' ');
        cout << N << "\n";
    }
    return 0;
}

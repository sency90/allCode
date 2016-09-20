#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> kmp(const string &H, const string &N) {
    int h=H.size(), n=N.size();
    vector<int> pi(n,0), ret;
    for(int i=1, matched=0; i<n; i++) {
        while(matched!=0 && N[i]!=N[matched]) matched=pi[matched-1];
        if(N[i]==N[matched]) pi[i]=++matched;
    }
    for(int i=0, matched=0; i<h; i++) {
        while(matched!=0 && H[i]!=N[matched]) matched=pi[matched-1];
        if(H[i]==N[matched]) {
            if(++matched==n) {
                ret.push_back(i+1-matched);
                matched=pi[matched-1];
            }
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string H,N;
    cin >> H >> N;
    vector<int> ans = kmp(H, N);
    for(auto &p : ans) {
        for(int i=0; i<p; i++) putchar(' ');
        printf("%s\n", N.c_str());
    }
    return 0;
}

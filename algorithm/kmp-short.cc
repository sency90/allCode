#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
vector<int> kmp(const string &H, const string &N) {
    vector<int> pi(N.size(),0), ret;
    for(int i=1, matched=0; i<N.size(); i++) {
        while(matched!=0 && N[i]!=N[matched]) matched=pi[matched-1];
        if(N[i]==N[matched]) {
            matched++;
            pi[i]=matched;
        }
    }
    for(int i=0, matched=0; i<H.size(); i++) {
        while(matched!=0 && H[i]!=N[matched]) matched=pi[matched-1];
        if(H[i]==N[matched]) {
            matched++;
            if(matched==N.size()) ret.push_back(i-matched+1);
        }
    }
    return ret;
}
int main() {
    string H, N;
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> H >> N;
    vector<int> ans = kmp(H, N);
    for(auto &p : ans) {
        for(int i=0; i<p; i++) {
            putchar(' ');
        }
        printf("%s\n", N.c_str());
    }
    return 0;
}

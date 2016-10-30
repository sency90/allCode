#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
void kmp(const string &H, const string &N) {
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
    printf("%lu\n", ret.size());
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    string N,H="pen-pineapple-apple-pen/";
    for(int i=0; i<16; i++) H+=H;
    cin >> N;
    kmp(H.substr(n-1,m-n+1), N);
    return 0;
}

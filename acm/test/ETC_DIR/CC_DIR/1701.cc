#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> getPartialTable(const string &N) {
    int n = N.size();
    vector<int> pi(n,0);
    int b=1, m=0;
    while(b+m <= n) {
        if(N[b] == N[b+m]) {
            m++;
            pi[b+m-1]=m;
        } else {
            if(m==0) b++;
            else {
                b += m-pi[m-1];
                m = pi[m-1];
            }
        }
    }
    return pi;
}
vector<int> kmp(const string &H, const string &N) {
    vector<int> pi = getPartialTable(N);
    vector<int> ret;
    int h=H.size(), n=N.size();
    int b=0, m=0;
    while(n+b<=h) {
        if(m<n && H[b+m]==N[m]) {
            m++;
            if(m==n) ret.push_back(b);
        } else {
            if(m==0) b++;
            else {
                b += m-pi[m-1];
                m = pi[m-1];
            }
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    string H, N;
    cin >> H >> N;
    vector<int> ret = kmp(H, N);
    for(auto &p : ret) {
        cout << p << ": " << H.substr(p, N.size()) << "\n";
    }
    return 0;
}

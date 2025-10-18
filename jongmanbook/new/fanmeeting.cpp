#include <bits/stdc++.h>
using namespace std;
string H, N;
vector<int> pi;
void GetFailFunc(const string & N) {
    int m = N.size();
    int begin=1, matched=0;
    pi.clear(); pi.resize(m, 0);
    while(begin+matched < m) {
        if(N[begin + matched] == N[matched]) {
            matched++;
            pi[begin+matched-1] = matched;
        } else {
            if(matched==0) begin++;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
}
vector<int> result;
vector<int> & Kmp(const string & H, const string & N) {
    if(H.size() < N.size()) return Kmp(N,H);

    result.clear();
    GetFailFunc(N);
    int n = H.size(), m = N.size();
    int begin=0, matched=0;
    while(begin+m <= n) {
        if(H[begin + matched] == N[matched]) {
            matched++;
            if(matched == m) {
                result.push_back(begin);
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
        else {
            if(matched==0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> N >> H;
        vector<int> & ans = Kmp(H,N);
    }
    cin >> H >> N;
    vector<int> & ans = Kmp(H,N);
    printf("%s\n", H.c_str());
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i]; j++) putchar(' ');
        printf("%s\n", N.c_str());
    }
    return 0;
}
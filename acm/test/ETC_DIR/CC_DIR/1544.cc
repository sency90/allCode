#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> sfx;
bool kmp(const string &H, const string &N) {
    int h=H.size(), n=N.size();
    vector<int> pi(n);
    int begin=1, matched=0;
    while(begin+matched<n) {
        if(N[begin+matched]==N[matched]) {
            ++matched;
            pi[begin+matched-1] = matched;
        } else {
            if(matched==0) begin++;
            else {
                begin+=matched-pi[matched-1];
                matched=pi[matched-1];
            }
        }
    }


    begin=0, matched=0;
    while(begin+matched<h) {
        if(matched<n && H[begin+matched]==N[matched]) {
            matched++;
            if(matched == n) return true;
        } else {
            if(matched==0) begin++;
            else {
                begin += matched-pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return false;
}
string H[51], N;
int h[51];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    cin >> H[0];
    h[0] = H[0].size();
    H[0] = H[0]+H[0];
    int cnt = 1;
    for(int i=1; i<n; i++) {
        cin >> N;
        bool good=false;
        for(int j=0; j<cnt; j++) {
            if(h[j]==N.size() && kmp(H[j],N)) good=true;
        }
        if(!good) {
            h[cnt]=N.size();
            H[cnt]=N+N;
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}

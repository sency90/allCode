#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
char H[1000001], N[1000001];
int h, n;
vector<int> getPartialTable() {
    vector<int> pi(n, 0);
    int begin=1, matched=0;
    while(begin+matched<n) {
        if(N[begin+matched]==N[matched]) {
            matched++;
            pi[begin+matched-1] = matched;
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
vector<int> kmp() {
    vector<int> pi = getPartialTable();
    vector<int> ret;
    int begin=0, matched=0;
    while(begin+matched<h) {
        if(matched<n && H[begin+matched] == N[matched]) {
            matched++;
            if(matched==n) ret.push_back(begin+1);
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
    scanf("%[^\n]\n", H);
    scanf("%[^\n]\n", N);
    h=strlen(H), n=strlen(N);
    vector<int> ans = kmp();

    printf("%lu\n", ans.size());
    for(auto &p : ans) {
        printf("%d ", p);
    }
    return 0;
}

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> getPi(const string &N) {
    vector<int> pi(N.size(), 0);
    int n = N.size();
    for(int i=1, matched=0; i<n; i++) {
        while(matched!=0 && N[i]!=N[matched]) matched=pi[matched-1];
        if(N[i]==N[matched]) {
            matched++;
            pi[i]=matched-1;
        }
    }
    return pi;
}
vector<int> pi[2];
int kmp(const string &H, const string &N, int start, int lim, int z) {
    for(int i=0, matched=0; i<lim; i++) {
        while(matched!=0 && H[i]!=N[matched]) matched=pi[z][matched-1];
        if(H[i]==N[matched]) {
            matched++;
            if(matched==n) return i-matched+1;
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string a[2], t[2];
    cin >> a[0] >> t[0];
    n=a[0].size();
    if(a[0].size()>t[0].size()) cout << t[0];
    else {
        a[1]=a[0]; reverse(a[1].begin(), a[1].end());
        pi[0]=getPi(a[0]); pi[1]=getPi(a[1]);

        t[1]=t[0]; reverse(t[1].begin(), t[1].end());
        int idx, lim=t[0].size(), start[2]={0,0};
        for(int i=0;;i^=1) {
            idx = kmp(t[i],a[i],start[i],lim,i);
            if(idx==-1) break;
            else {
                int sz = t[i].size();
                t[i^1]=t[i^1].substr(0,sz-idx-n)+t[i^1].substr(sz-idx);
                t[i]=t[i].substr(0,idx)+t[i].substr(idx+n);
                start[i]=max(0,idx-n);
                lim=min(sz-idx+n, (int)t[i].size());
            }
        }
        cout << t[0];
    }

    return 0;
}

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a;
int f(vector<int> &v, int bit) {
    if(v.empty() || bit<0) return 0LL;

    vector<int> l,r;
    for(int &x: v) {
        if((x>>bit)&1) r.push_back(x);
        else l.push_back(x);
    }

    if(l.empty() || r.empty()) return f(l.empty()?r:l, bit-1);
    else return min(f(l,bit-1), f(r,bit-1)) | (1<<bit);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    a.clear(); a.resize(n,0);
    for(int i=0; i<n; i++) cin >> a[i];

    printf("%d", f(a,30));
    return 0;
}

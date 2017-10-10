#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
struct Info{
    int sz, idx;
    Info(){} Info(int sz, int idx):sz(sz),idx(idx) {}
};
Info v[1000001];
string str[1000001];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int term=0;
    for(int i=0; i<n; i++) {
        int k; cin >> str[i] >> k;
        while(k--) {
            int idx; cin >> idx;
            idx--;
            term = max(term, int(idx+str[i].size()));
            if(v[idx].sz < str[i].size()) {
                v[idx].sz = str[i].size();
                v[idx].idx = i;
            }
        }
    }
    int f=-1;
    for(int i=0; i<term; i++) {
        if(i>1000000) {
            if(f<i) putchar('a');
            else continue;
        } else if(v[i].sz) {
            int j=f-i+1;
            for(;j<v[i].sz;j++) putchar(str[v[i].idx][j]);
            f=max(f,i+j-1);
        } else if(i>f) {
            putchar('a');
            f = max(f,i);
        }
    }
    return 0;
}

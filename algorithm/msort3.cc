#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
vector<int> v;
void merge(vector<int> &v, vector<int> &l, vector<int> &r) {
    v.clear();
    int i=0,j=0;
    while(i<l.size() && j<r.size()) {
        if(l[i]<r[j]) v.emplace_back(l[i++]);
        else v.emplace_back(r[j++]);
    }
    while(i<l.size()) v.emplace_back(l[i++]);
    while(j<r.size()) v.emplace_back(r[j++]);
}
void msort(vector<int>& v) {
    if(v.size() <= 1) return;
    vector<int> l(v.begin(), v.begin()+v.size()/2);
    vector<int> r(v.begin()+v.size()/2, v.end());
    msort(l); msort(r);
    merge(v,l,r);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    v.resize(n,0);
    for(int i=0; i<n; i++) cin >> v[i];
    msort(v);
    for(int i=0; i<v.size(); i++) cout << v[i] <<" ";
    cout << "\n";
    return 0;
}

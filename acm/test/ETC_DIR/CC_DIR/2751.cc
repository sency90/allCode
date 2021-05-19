#include <stdio.h>
#include <vector>
using namespace std;
template <typename T> void merge(vector<T>& v, vector<T>& lhs, vector<T>& rhs) {
    v.clear();
    int l, r;
    for(l=0, r=0; l<lhs.size() && r<rhs.size();) {
        if(lhs[l] < rhs[r]) v.push_back(lhs[l++]);
        else v.push_back(rhs[r++]);
    }
    while(l<lhs.size()) v.push_back(lhs[l++]);
    while(r<rhs.size()) v.push_back(rhs[r++]);
}
template <typename T> void msort(vector<T>& v) {
    if(v.size() <= 1) return;
    vector<T> l(v.begin(), v.begin()+v.size()/2);
    vector<T> r(v.begin()+v.size()/2, v.end());
    msort(l);
    msort(r);
    merge(v, l, r);
}
vector<int> v;
int main() {
    int n;
    scanf("%d", &n);
    v.resize(n);
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    msort(v);
    for(auto x : v) printf("%d\n", x);
    return 0;
}

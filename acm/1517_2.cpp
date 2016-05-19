#include <stdio.h>
#include <vector>
using namespace std;
long long cnt=0;
void merge(vector<int>& v, vector<int>& lhs, vector<int>& rhs) {
    v.clear();
    int l, r;
    for(l=0, r=0; l<lhs.size() && r<rhs.size();) {
        if(lhs[l] < rhs[r]) v.push_back(lhs[l++]);
        else {
            v.push_back(rhs[r++]);
            cnt += (long long)lhs.size()-l;
        }
    }
    while(l<lhs.size()) v.push_back(lhs[l++]);
    while(r<rhs.size()) v.push_back(rhs[r++]);
}
void msort(vector<int>& v) {
    if(v.size() <= 1) return;
    vector<int> l(v.begin(), v.begin()+v.size()/2);
    vector<int> r(v.begin()+v.size()/2, v.end());
    msort(l);
    msort(r);
    merge(v, l, r);
}
vector<int> v;
int main() {
    int n, d;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        v.push_back(d);
    }
    msort(v);
    printf("%lld", cnt);
    return 0;
}

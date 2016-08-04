#include <stdio.h>
#include <vector>
using namespace std;
int cnt;
void merge(vector<int> &v, vector<int> &l, vector<int> &r) {
    v.clear();
    int i=0, j=0;
    while(i<l.size() && j<r.size()) {
        if(l[i]<=r[j]) v.push_back(l[i++]);
        else {
            v.push_back(r[j++]);
            cnt+=l.size()-i;
        }
    }
    while(i<l.size()) v.push_back(l[i++]);
    while(j<r.size()) v.push_back(r[j++]);
}
void msort(vector<int> &v) {
    if(v.size()<=1) return;
    vector<int> l(v.begin(), v.begin()+v.size()/2);
    vector<int> r(v.begin()+v.size()/2, v.end());
    msort(l); msort(r);
    merge(v,l,r);
}
vector<int> v;
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n;
        scanf("%d", &n);
        v.resize(n);
        cnt=0;
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }
        msort(v);
        printf("%d\n", cnt);
    }
    return 0;
}

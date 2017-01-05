#include <cstdio>
#include <vector>
using namespace std;
void merge(vector<int>& v, vector<int>& l, vector<int>& r) {
    v.clear();
    int i=0, j=0;
    while(i<l.size() && j<r.size()) {
        if(l[i]<r[j]) v.push_back(l[i++]);
        else v.push_back(r[j++]);
    }
    while(i<l.size()) v.push_back(l[i++]);
    while(j<r.size()) v.push_back(r[j++]);
}
void msort(vector<int>& v) {
    if(v.size()<=1) return;
    vector<int> l(v.begin(), v.begin()+v.size()/2);
    vector<int> r(v.begin()+v.size()/2, v.end());
    msort(l); msort(r);
    merge(v,l,r);
}
int main()  {
    vector<int> v;
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        v.push_back(x);
    }
    msort(v);
    for(int i=0; i<n; i++) {
        printf("%d ", v[i]);
    }
    puts("");
    return 0;
}

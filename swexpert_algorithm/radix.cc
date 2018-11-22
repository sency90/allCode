#include "Vector.h"
#include <cstdio>
using namespace std;
template <class T>
class Less{
public:
    Less() {}
    bool operator()(const T& lhs, const T& rhs) const { return lhs<rhs; }
};
template <class T>
class Greater{
public:
    Greater() {}
    bool operator()(const T& lhs, const T& rhs) const { return rhs<lhs; }
};
template <class T=int, class Cmp = Less<T> >
void sort(int MAX, Vector<T>& v, Vector<int>& idx, Vector<int>& ret) {
    Cmp cmp;
    int n = v.size();
    Vector<T> cnt; cnt.resize(MAX+1);
    for(int i=0; i<=MAX; i++) cnt[i] = 0;
    ret.clear(); ret.resize(n);

    for(int i=0; i<n; i++) cnt[v[i]]++;
    for(int i=1; i<=MAX; i++) cnt[i]+=cnt[i-1];
    if(cmp(0,1)) {
        for(int i=n-1; i>=0; i--) ret[--cnt[v[idx[i]]]] = i;
    } else {
        for(int i=n-1; i>=0; i--) ret[n-cnt[v[idx[i]]]--] = i;
    }
}
int main() {
    freopen("input2.txt", "r", stdin);
    Vector<int> v;
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d",&x);
        v.push_back(x);
    }

    Vector<int> idx, ans;
    for(int i=0; i<v.size(); i++) idx.push_back(i);
    sort(20, v, idx, ans);
    for(int i=0; i<ans.size(); i++) {
        printf("%d ", v[ans[i]]);
    }
    return 0;
}

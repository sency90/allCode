#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Fenwick{
    vector<long long> tree;
    Fenwick(int n) : tree(n+1,0LL) {}

    void add(int pos, long long val) {
        for(int i=pos; i<=tree.size(); i+=(i&-i)) {
            tree[i] += val;
        }
    }

    long long sum(int pos) {
        if(pos==0) return 0LL;
        long long ret=0LL;
        for(int i=pos; i!=0; i&=(i-1)) {
            ret += tree[i];
        }
        return ret;
    }
};
vector<long long> v;
int main() {
    int n,m,k,a,b,c;
    scanf("%d%d%d",&n,&m,&k);
    Fenwick fw(n);
    v.resize(n+1);
    for(int i=1; i<=n; i++) {
        scanf("%lld", &v[i]);
        fw.add(i,v[i]);
    }
    int t=m+k;
    for(int i=0; i<t; i++) {
        scanf("%d%d%d",&a,&b,&c);
        if(a==1) {
            fw.add(b,c-v[b]);
            v[b]=c;
        } else {
            if(b>c) swap(b,c);
            printf("%lld\n", fw.sum(c)-fw.sum(b-1));
        }
    }
    return 0;
}

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int d[10001];
struct Item {
    int w, v, k; //w:무게, v:가치, k:개수
    Item() {}
    Item(int ww, int vv, int kk) {w=ww;v=vv;k=kk;}
    bool operator<(const Item &rhs) const {
        return w > rhs.w;
    }
};
vector<Item> item;
int n,m,w,v,k;
int f(int x) {
    if(x<=0) return 0;
    if(d[x]>0) return d[x];
    int mx = 0;
    for(int i=0; i<item.size(); i++) {
        for(int j=0; j<=m; j+=item[i].w) {
            mx = max(f(x-j)+item[i].v, mx);
        }
    }
    return d[x] = mx;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%d%d%d", &w,&v,&k);
        item.push_back(Item(w,v,k));
    }
    sort(item.begin(), item.end());

    printf("%d", f(m));
    return 0;
}

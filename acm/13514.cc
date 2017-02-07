#include <cstdio>
#include <vector>
using namespace std;
const int B=0, W=1;
vector<int> v[100001];
int del[100001], vcnt[100001];
void vcounting(int x, int px) {
    vcnt[x]=1;
    for(int y: v[x]) {
        if(del[y] || y==px) continue;
        vcounting(y,x);
        vcnt[x]+=vcnt[y];
    }
}
int getcr(int x, int px, int halftsz) {
    for(int y: v[x]) {
        if(del[y] || y==px) continue;
        if(vcnt[y]>halftsz) return getcr(y,x,halftsz);
    }
    return x;
}
int solve(int r) {
    vcounting(r,r);
    int cr = getcr(r,r,vcnt[r]>>1);
    cen[r]=cr;
    del[cr]=true;

}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int m; scanf("%d", &m);
    for(int i=0; i<m; i++) {
        int type,d;
        scanf("%d%d",&type,&d);
        if(type==1) color[d]^=1;
        else {
            if(color[d]==W) puts("0");
            else printf("%d\n", solve(d));
        }
    }
    solve(1);
    return 0;
}

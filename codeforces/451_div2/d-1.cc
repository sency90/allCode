#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int v[200001], fen[1000001];
void update(int i, int by) {
    if(i==0) return;
    for(;i<=1000000; i+=i&-i) fen[i]+=by;
}
int query(int i) {
    if(i==0) return 0;
    int ret=0;
    for(;i;i-=i&-i) ret+=fen[i];
    return ret;
}
int main() {
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    sort(v,v+n);
    int ans=0;
    for(int i=0; i<n; i++) {
        update(v[i],1);
        if(query(v[i])-query(max(v[i]-m,0))>=k) {
            update(v[i],-1);
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}

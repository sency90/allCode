#include <cstdio>
using namespace std;
int v[100001], tmp[100001];
void merge(int l, int m, int r) {
    int i=l,j=m,k=l;
    while(i<m && j<r) {
        if(v[i]<v[j]) tmp[k++]=v[i++];
        else tmp[k++]=v[j++];
    }
    while(i<m) tmp[k++]=v[i++];
    while(j<r) tmp[k++]=v[j++];
    for(i=l; i<r; i++) v[i]=tmp[i];
}
void msort(int l, int r) { //[l,r)
    if(l+1>=r) return;
    int m = (l+r)/2;
    msort(l,m); msort(m,r);
    merge(l,m,r);
}
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    msort(0,n);
    for(int i=0; i<n; i++) {
        printf("%d ", v[i]);
    } puts("");
    return 0;
}

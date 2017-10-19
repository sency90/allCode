#include <stdio.h>
int v[100001],tmp[100001];
void merge(int s, int m, int e) {
    int i=s,j=m+1,k=s;
    while(i<=m && j<=e) {
        if(v[i]<v[j]) tmp[k++]=v[i++];
        else tmp[k++]=v[j++];
    }
    while(i<=m) tmp[k++] = v[i++];
    while(j<=e) tmp[k++] = v[j++];
    for(int i=s; i<=e; i++) v[i]=tmp[i];
}
void msort(int s, int e) {
    if(s==e) return;
    int m=(s+e)>>1;
    msort(s,m); msort(m+1,e);
    merge(s,m,e);
}
int main() {
    int n; scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    msort(0,n-1);
    return 0;
}

#include <stdio.h>
int v[100001], t[100001];
inline bool cmp(int x, int y, int c) {
    if(!c) return x<y;
    else return x>y;
}
int c;
inline void merge(int s, int m, int e) {
    int i=s,j=m+1,k=s;
    while(i<=m && j<=e) {
        if(cmp(v[i],v[j],c)) t[k++]=v[i++];
        else t[k++]=v[j++];
    }
    while(i<=m) t[k++]=v[i++];
    while(j<=e) t[k++]=v[j++];
    for(i=s; i<=e; i++) v[i]=t[i];
}
inline void msort(int s, int e) {
    if(s==e) return;
    int m = (s+e)/2;
    msort(s,m); msort(m+1,e);
    merge(s,m,e);
}
int main() {
    int n; scanf("%d%d", &n,&c);
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    msort(0,n-1);
    for(int i=0; i<n; i++) printf("%d\n", v[i]);
    return 0;
}

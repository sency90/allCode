#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
template <class T>
void merge(T *v, int vsz, T *l, int lsz, T *r, int rsz) {
    int i=0, j=0, idx=0;
    while(i<lsz && j<rsz) {
        if(l[i]<r[j]) v[idx++]=l[i++];
        else v[idx++]=r[j++];
    }
    while(i<lsz) v[idx++]=l[i++];
    while(j<rsz) v[idx++]=r[j++];
}
template <class T>
void msort(T *v, int vsz) {
    if(vsz<=1) return;
    int lsz = vsz/2, rsz = vsz-lsz;
    T *l = (T*)malloc(lsz*sizeof(*v));
    for(int i=0; i<lsz; i++) l[i]=v[i];
    T *r = (T*)malloc(rsz*sizeof(*v));
    for(int i=lsz, j=0; i<vsz; i++, j++) r[j]=v[i];
    msort(l,lsz); msort(r,rsz);
    merge(v,vsz,l,lsz,r,rsz);
    free(l); free(r);
}
typedef long long ll;
int v[1001];
int main() {
    //freopen("input.txt", "r", stdin);
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    msort(v,n);
    ll ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int dif = v[j]-v[i];
            int *p = lower_bound(v+j,v+n,v[j]+dif);
            int *q = upper_bound(v+j,v+n,v[j]+dif*2);
            int idx = q - p;
            //printf("%d %d\n", *p, *q);
            ans+=idx;
            //printf("dif: %d, cnt: %d\n", dif,idx);
        }
    }
    printf("%lld\n", ans);
    return 0;
}

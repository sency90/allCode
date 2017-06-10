#include <iostream>
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
int v[30001];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    msort(v, n);
    for(int i=0; i<n; i++) printf("%d ", v[i]);
}

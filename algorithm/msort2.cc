#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int v[2001];
void merge(int *x, int xsz, int *l, int lsz, int *r, int rsz) {
    int i=0,j=0,z=0;
    while(i<lsz && j<rsz) {
        if(l[i]<r[j]) x[z++]=l[i++];
        else x[z++]=r[j++];
    }
    while(i<lsz) x[z++]=l[i++];
    while(j<rsz) x[z++]=r[j++];
}
void msort(int *x, int n) {
    if(n<=1) return;
    int lsz=n/2, rsz=n-lsz;

    int *l = (int*)malloc(lsz*sizeof(int));
    for(int i=0; i<lsz; i++) l[i]=x[i];

    int *r = (int*)malloc(rsz*sizeof(int));
    for(int i=lsz,j=0; j<rsz; i++,j++) r[j]=x[i];

    msort(l,lsz); msort(r,rsz);
    merge(x,n,l,lsz,r,rsz);
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    msort(v,n);
    for(int i=0; i<n; i++) {
        printf("%d ", v[i]);
    }
    puts("");
    return 0;
}


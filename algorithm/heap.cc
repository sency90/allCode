#include <cstdio>
using namespace std;
int v[100001];
inline void swap(int &x, int &y) {
    x^=y; y^=x; x^=y;
}
void heapify(int n, int cur) {
    int mxidx=cur, l=2*cur+1, r=2*cur+2;
    if(l<n && v[l]>v[mxidx]) mxidx=l;
    if(r<n && v[r]<v[mxidx]) mxidx=r;

    if(mxidx!=cur) {
        swap(v[mxidx],v[cur]);
        heapify(n,mxidx);
    }
}
void heapsort(int n) {
    for(int i=(n-1)/2; i>=0; i--) {
        heapify(n,i);
    }

    for(int i=n-1; i>=0; i--) {
        swap(v[0],v[i]);
        heapify(i,0);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }

    return 0;
}

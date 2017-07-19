#include <stdio.h>
template <typename T>
struct Heap{
    Heap(){}
    int sz=0;
    T v[100001];
    void swap(T &x, T &y) {
        T tmp=x; x=y; y=tmp;
    }
    void heapify(int n, int cur) {
        int mxi=cur, l=cur*2, r=cur*2+1;
        if(l<n && v[l]>v[mxi]) mxi=l;
        if(r<n && v[r]>v[mxi]) mxi=r;
        if(mxi!=cur) {
            swap(v[mxi], v[cur]);
            heapify(n, mxi);
        }
    }
    void makepush(int par, int ch) {
        if(par<1) return;
        else {
            if(v[par]<v[ch]) {
                swap(v[par], v[ch]);
                makepush(par/2,par);
            }
        }
    }
    void push(T x) {
        v[++sz]=x;
        makepush(sz/2, sz);
    }
    T pop() {
        T ret = v[1];
        v[1]=v[sz--];
        heapify(sz,1);
        return ret;
    }
};
int main() {
    int n; scanf("%d", &n);
    Heap<int> h;
    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        h.push(x);
    }
    while(h.sz>=1) {
        printf("%d\n", h.pop());
    }
    return 0;
}

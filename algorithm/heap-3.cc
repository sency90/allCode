#include <cstdio>
using namespace std;
int v[100001];
template <typename T>
struct Heap{
    int sz;
    T v[100001];
    Heap():sz(0){}
    T top() {return v[1];}
    void swap(T &x, T &y) { x^=y; y^=x; x^=y; }
    void down(int c) { //for pop
        if(c>=sz) return;
        int l=c*2, r=c*2+1, mxi=c;
        if(l<=sz && v[mxi]<v[l]) mxi=l;
        if(r<=sz && v[mxi]<v[r]) mxi=r;
        if(mxi != c) {
            swap(v[c], v[mxi]);
            down(mxi);
        }
    }
    void up(int c) { //for push
        if(c<=1) return;
        if(v[c/2]<v[c]) {
            swap(v[c/2], v[c]);
            up(c/2);
        }
    }
    void pop() {
        swap(v[1], v[sz--]);
        down(1);
    }
    void push(T x) {
        v[++sz] = x;
        up(sz);
    }
    void clear() { sz=0; }
    bool empty() { return sz==0; }
};
Heap<int> h;
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        h.push(x);
    }
    while(!h.empty()) {
        printf("%d ", h.top()); h.pop();
    }
    puts("");
}

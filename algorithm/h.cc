#include <cstdio>
#include <cassert>
using namespace std;
template <typename T>
struct MinHeap{
    MinHeap():sz(0) {}
    int sz;
    T v[10001];

    void swap(T & lhs, T & rhs) {
        T tmp = lhs; lhs = rhs; rhs = tmp;
    }



    //1. void push(T);
    void push(T x) {
        v[++sz] = x;
        pushup(sz);
    }
    void pushup(int cur) {
        if(cur<=1) return; //root
        int par = cur>>1;
        if(v[cur] < v[par]) {
            swap(v[cur], v[par]);
            pushup(par);
        }
    }

    //2. T pop()
    T top() const {
        assert(sz>=1);
        return v[1];
    }
    void pop() {
        v[1] = v[sz--];
        popdown(1);
    }
    void popdown(int cur) {
        int l=cur*2, r=cur*2+1;
        int mni=cur;
        if(l<=sz && v[mni] > v[l]) mni=l;
        if(r<=sz && v[mni] > v[r]) mni=r;
        if(mni != cur) {
            swap(v[mni], v[cur]);
            popdown(mni);
        }
    }

};
MinHeap<int> mnh;
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        mnh.push(x);
    }
    while(mnh.sz >= 1) {
        printf("%d\n", mnh.top());
        mnh.pop();
    }
}

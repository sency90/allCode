#include <cstdio>
#include <iostream>
#include "Vector.h"
using namespace std;
template <typename T>
class Heap{
public:
    int sz;
    bool (*compare)(T x, T y);
    bool cmp(T x, T y) { return x>y; }
    Vector<int> v;
    Heap():sz(0){}
    Heap(bool (*comp)()):compare(comp),sz(0){}

    void swap(T &x, T &y) { T tmp = x; x=y; y=tmp; }
    void up(int ch) {
        int p = (ch-1)/2;
        if(compare(v[sz], v[ch])) {
            swap(v[sz],v[ch]);
            up(p);
        }
    }
    void push(T x) {
        v.push_back(x);
        sz = v.size();
        up(sz-1);
    }

    void down(int p) {
        int l=(p>>1)+1, r=(p>>1)+2, mx=p;
        if(l<sz && cmp(v[l],v[mx])) mx=l;
        if(r<sz && cmp(v[r],v[mx])) mx=r;
        if(mx!=p) {
            swap(v[mx], v[p]);
            down(mx);
        }
    }
    T top() { return v[0]; }
    T pop() {
        v.pop_back();
        sz = v.size();
        if(sz>=1) {
            v[0]=*(v.end()-1);
            down(0);
        }
    }
    bool empty() { return (sz==0); }
};
template <class T>
bool cmp(T x, T y) { return x>y; }
int main() {
    Heap<int> mxh(&cmp);
    mxh.push(4); mxh.push(3); mxh.push(6); mxh.push(7); mxh.push(10);
    while(!mxh.empty()) {
        printf("%d ", mxh.top()); mxh.pop();
    }
    return 0;
}

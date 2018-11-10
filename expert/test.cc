#include <stdio.h>
#include <stdlib.h>
template <class T>
struct Vector{
    int sz,idx;
    T *arr;
    Vector():sz(1),idx(0){
        arr = (T*)malloc(sizeof(T));
    }
    ~Vector() {
        if(arr) free(arr);
    }

    //private functions
    void expand(int& size) {
        size*=2;
        do { arr = (T*)realloc(arr, size*sizeof(T)); } while(arr==NULL);
    }

    //public functions
    void push_back(const T& x) {
        if(idx>=sz) expand(sz);
        arr[idx++] = x;
    }
    void pop_back() {
        idx--;
    }
    bool empty() { return idx==0; }
    int size() { return idx; }
    void clear() { idx=0; }
    T& operator[](const int at) const { return arr[at]; }
};

template <class T>
struct Less{
    bool operator()(const T& lhs, const T& rhs) const {
        return lhs<rhs;
    }
};
template <class T>
struct Greater{
    bool operator()(const T& lhs, const T& rhs) const {
        return rhs<lhs;
    }
};


template <class T, class Container = Vector<T>, class Cmp = Less<T> >
struct Heap{
    int sz;
    Container v;
    Cmp cmp;

    Heap():sz(0) {
        v.clear();
        v.push_back(T(0));
    }

    void swap(T& x, T& y) {
        T tmp=x; x=y; y=tmp;
    }
    void push(const T& x) {
        v.push_back(x); sz++;
        up(v.size()-1);
    }
    void up(int at) {
        if(at<=1) return;
        int par = at/2;
        if(cmp(v[par],v[at])) {
            swap(v[par], v[at]);
            up(par);
        }
    }

    void pop() {
        v[1]=v[sz]; v.pop_back(); sz--;
        down(1);
    }
    void down(int at) {
        int l=at*2, r=at*2+1, pos=at;
        if(l<=sz) if(cmp(v[pos],v[l])) pos=l;
        if(r<=sz) if(cmp(v[pos],v[r])) pos=r;
        if(pos!=at) {
            swap(v[at],v[pos]);
            down(pos);
        }
    }
    T top() const {
        if(sz<=0) exit(1);
        return v[1];
    }

    int size() { return sz; }
    bool empty() { return sz<=0; }
    void clear() {
        sz=0;
        v.clear();
    }
};

Heap<int> mxh;
Heap<int, Vector<int>, Greater<int> > mnh;

int main() {
    freopen("input2.txt", "r", stdin);
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        mxh.push(x);
        mnh.push(x);
        printf("MXH LIST: ");
        for(int i=1; i<=mxh.sz; i++) printf("%d ", mxh.v[i]);
        puts("");
        printf("MNH LIST: ");
        for(int i=1; i<=mnh.sz; i++) printf("%d ", mnh.v[i]);
        puts("");
        if(i%5 == 4) {
            mxh.pop();
            mnh.pop();
        }
    }
    printf("MaxHeap: ");
    while(!mxh.empty()) {
        int top = mxh.top(); mxh.pop();
        printf("%d ", top);
    }
    puts("");
    printf("MinHeap: ");
    while(!mnh.empty()) {
        int top = mnh.top(); mnh.pop();
        printf("%d ",top);
    }
    puts("");
    return 0;
}

#include <cstdio>
#define MAX_N 100001
using namespace std;
struct Info{
    int x,y;
    Info(){} Info(int x, int y):x(x),y(y){}
    bool operator<(const Info& rhs) const {
        if(x==rhs.x) return y<rhs.y;
        else return x<rhs.x;
    }
    void print() const {
        printf("(%d,%d)",x,y);
    }
};
template <class T>
struct Greater{
    bool operator()(const T& lhs, const T& rhs) const {
        return lhs<rhs;
    }
};
template <class T>
struct Less{
    bool operator()(const T& lhs, const T& rhs) const {
        return rhs<lhs;
    }
};
template <class T, class Cmp = Less<T>>
struct MaxHeap{
    int sz;
    T arr[MAX_N];
    Cmp cmp;
    //bool *cmp(T& lhs, T& rhs);
    MaxHeap():sz(0){}
    void swap(T& x, T& y) { T tmp=x; x=y; y=tmp; }
    void push(T x) {
        arr[++sz] = x;
        up(sz);
    }
    void up(int at) {
        if(at<=1) return;
        int par = at/2;
        if(cmp(arr[par],arr[at])) {
            swap(arr[par],arr[at]);
            up(par);
        }
    }
    void pop() {
        if(sz==0) return;
        arr[1]=arr[sz--];
        down(1);
    }
    void down(int at) {
        int pos=at,l=at*2,r=at*2+1;
        if(l<=sz) if(cmp(arr[pos],arr[l])) pos=l;
        if(r<=sz) if(cmp(arr[pos],arr[r])) pos=r;
        if(at!=pos) {
            swap(arr[at],arr[pos]);
            down(pos);
        }
    }
    T top() {
        return arr[1];
    }
    bool empty() const { return sz<=0; }
};
MaxHeap<Info, Greater<Info>> mxh;
int main() {
    freopen("input.txt","r",stdin);
    int n,x,y; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &x,&y);
        mxh.push(Info(x,y));
    }
    while(!mxh.empty()) {
        Info x = mxh.top(); mxh.pop();
        x.print();
    }
    return 0;
}

#include <stdio.h>
#include <iostream>
using namespace std;

template <class T>
class Heap{
public:
    int sz;
    T v[100001];
    Heap():sz(0){}
    void swap(T &x, T &y) { T tmp=x; x=y; y=tmp; }

    void up(int x) {
        if(x<=0) return;
        int p = (x-1)/2;
        if(v[p] > v[x]) {
            swap(v[p],v[x]);
            up(p);
        }
    }
    void push(T x) {
        v[sz] = x;
        up(sz++);
    }

    void down(int p) {
        int l=p*2+1, r=p*2+2, mn=p;
        if(l<sz && v[mn]>v[l]) mn=l;
        if(r<sz && v[mn]>v[r]) mn=r;
        if(mn!=p) {
            swap(v[mn], v[p]);
            down(mn);
        }
    }
    T pop() {
        T tmp = v[0];
        v[0]=v[--sz];
        down(0);
        return tmp;
    }
    bool empty() { return sz==0; }
    int size() { return sz; }
};
int main() {
    //freopen("input.txt", "r", stdin);
    Heap<int> mnh;
    int n,x; 
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        mnh.push(x);
    }
    //printf("size: %d\n", mnh.size());
    int ans=0;
    while(true) {
        int x = mnh.pop();
        if(mnh.empty()) return 0&printf("%d\n", ans);

        int y = mnh.pop();
        //printf("x+y: %d\n", x+y);
        ans+=(x+y);
        mnh.push(x+y);
    }

    return 0;
}

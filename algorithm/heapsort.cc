#include <cstdio>
using namespace std;
template <typename T>
class Heap{
public:
    Heap(bool (*cmp)(const T&, const T&)):n(0),cmp(cmp){}
private:
    int n;
    bool (*cmp)(const T &x, const T &y);
    T v[100001];
    void swap(T &x, T &y) { T t=x; x=y; y=t; }
    void heapify(int i, int n) {
        int mxidx=i, l=i*2+1, r=i*2+2;
        if(l<n && cmp(v[l], v[mxidx])) mxidx=l;
        if(r<n && cmp(v[r], v[mxidx])) mxidx=r;
        if(mxidx!=i) {
            swap(v[mxidx], v[i]);
            heapify(mxidx,n);
        }
    }

public:
    bool empty() { return n==0; }
    T size() { return n; }
    void push(T x) {
        v[n]=x;
        int p=(n-1)/2;
        for(int i=n++; p>=0 && cmp(v[i],v[p]);) {
            swap(v[p],v[i]);
            i=p;
            p=(i-1)/2;
        }
    }

    T top() {
        if(n==0) return 0&puts("Error");
        else return v[0];
    }
    T pop() {
        int tmp = v[0];
        if(n==0) return 0&puts("Error");
        else v[0]=v[--n];

        heapify(0,n);
        return tmp;
    }
};

template <typename T> bool gt(const T &x, const T &y) { return x>y; }
template <typename T> bool lt(const T &x, const T &y) { return x<y; }
template <typename T> bool gte(const T &x, const T &y) { return x>=y; }
template <typename T> bool lte(const T &x, const T &y) { return x<=y; }
Heap<int> mxh(gt<int>);
Heap<int> mnh(lt<int>);
int main() {
    int n; scanf("%d",&n);
    for(int i=0; i<n ;i++) {
        int d; scanf("%d", &d);
        mxh.push(d);
    }
    for(int i=0; i<n; i++) {
        printf("%d ", mxh.pop());
    } puts("");
    return 0;
}

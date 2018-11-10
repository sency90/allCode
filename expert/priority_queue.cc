#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define N 1001
template <typename T>
struct MaxHeap{
    int sz,idx;
    T arr[N];
    MaxHeap():sz(0){
        //for(int i=0; i<N; i++) arr[i] = 0;
    }

    void swap(T x, T y) {
        T tmp = x;
        x = y;
        y = tmp;
    }

    void push(const T &x) {
        arr[++sz] = x;
        up(sz);
    }
    void up(int at) {
        if(at==1) return;
        int par = at/2;
        if(arr[par]<arr[at]) {
            swap(arr[par],arr[at]);
            up(par);
        }
    }

    T top() const {
        return arr[1];
    }
    void pop() {
        arr[1] = arr[sz--];
        down(1);
    }
    void down(int at) {
        int l=at*2, r=at*2+1, pos=at;
        if(l<=sz) if(arr[pos] < arr[l]) pos=l;
        if(r<=sz) if(arr[pos] < arr[r]) pos=r;
        if(pos!=at) {
            swap(arr[at], arr[pos]);
            down(pos);
        }
    }
    bool empty() const { return sz==0; }
    int size() const {return sz;}
    void print() {
        printf("list: ");
        for(int i=1; i<=sz; i++) {
            printf("%d ", arr[i]);
        }
        puts("");
    }
};
MaxHeap<int> mxh;
int main() {
    freopen("input.txt","r",stdin);
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        mxh.push(x);
    }
    mxh.print();
    while(!mxh.empty()) {
        int x = mxh.top(); mxh.pop();
        printf("%d\n", x);
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
template <class T>
class Heap{
public:
    int sz;
    T v[300010];
    Heap():sz(0){}
    void swap(T &x, T &y) { T tmp=x; x=y; y=tmp; }

    void up(int x) {
        if(x<=0) return;
        int p = (x-1)/2;
        if(v[p] < v[x]) {
            swap(v[p],v[x]);
            up(p);
        }
    }
    void push(T x) {
        v[sz] = x;
        up(sz++);
    }

    void down(int p) {
        int l=p*2+1, r=p*2+2, mx=p;
        if(l<sz && v[mx]<v[l]) mx=l;
        if(r<sz && v[mx]<v[r]) mx=r;
        if(mx!=p) {
            swap(v[mx], v[p]);
            down(mx);
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
struct Info{
    int len, s;
    Info():len(0),s(0){}
    Info(int len, int s):len(len),s(s){}
    bool operator<(const Info &rhs) const {
        if(len == rhs.len) return s>rhs.s;
        else return len<rhs.len;
    }
};
int a[100010], b[100010];
Heap<Info> mxh;
int main() {
    //freopen("input.txt", "r", stdin);
    int m,n,q;
    scanf("%d%d%d",&m,&n,&q);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=q; i++) scanf("%d", &b[i]);
    int i;
    for(i=1; i<=q; i++) {
        if(b[i]<=n) printf("%d\n", a[b[i]]);
        else break;
    }

    a[0]=0;
    for(int i=1; i<=n; i++) {
        mxh.push(Info(a[i]-a[i-1]-1, a[i-1]+1));
    }
    if(m-a[n] > 0) mxh.push(Info(m-a[n], a[n]+1));

    int idx=i;
    for(int i=n+1; i<=b[q]; i++) {
        Info tmp = mxh.pop();
        int mid=tmp.s+(tmp.len-1)/2;
       // printf("len:%d s:%d mid:%d\n",tmp.len,tmp.s,mid);
        if(b[idx] == i) {
            printf("%d\n", mid);
            idx++;
        }
        //a[++n] = mid;
        if(mid-tmp.s>0) mxh.push(Info(mid-tmp.s,tmp.s));
        if(tmp.s+tmp.len-1-mid>0) mxh.push(Info(tmp.s+tmp.len-1-mid,mid+1));
    }
    return 0;
}

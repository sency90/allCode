#include "Heap.h"
#include <cstdio>
using namespace std;
struct Info{
    int x,y;
    Info(){} Info(int x, int y):x(x),y(y){}
    bool operator<(const Info& rhs) const {
        if(x==rhs.x) return y<rhs.y;
        else return x<rhs.x;
    }
    void print() {
        printf("(%d,%d)", x,y);
    }
};
Heap<Info> mxh;
int main() {
    freopen("input.txt","r",stdin);
    int n; scanf("%d", &n);
    for(int i=0; i<3; i++) {
        int x,y; scanf("%d%d",&x,&y);
        mxh.push(Info(x,y));
        mxh.print();
        puts("");
    }
    printf("Heap List: "); mxh.print(); puts("");
    while(mxh.size()>1) {
        Info info = mxh.top(); mxh.pop();
        info.print();
    }
    puts("");

    printf("Heap List: "); mxh.print(); puts("");
    for(int i=3; i<n; i++) {
        int x,y; scanf("%d%d",&x,&y);
        mxh.push(Info(x,y));
        mxh.print();
        puts("");
    }
    printf("Heap List: "); mxh.print(); puts("");
    while(mxh.size()>1) {
        Info info = mxh.top(); mxh.pop();
        info.print();
    }
    puts("");

    return 0;
}

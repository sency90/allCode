#include <cstdio>
using namespace std;
int n;
struct rect{
    int x1,y1,x2,y2;
    rect(){} rect(int x1, int y1, int x2, int y2):x1(x1),y1(y1),x2(x2),y2(y2){}
};
int ask(int x1, int y1, int x2, int y2) {
    printf("? %d %d %d %d\n",x1+1,y1+1,x2,y2);
    fflush(stdout);
    int cnt; scanf("%d", &cnt);
    return cnt;
}
int testx(int l, int r) {
    while(l+1<r) {
        int mid = (l+r)/2;
        if(ask(0,0,mid,n)>=1) r=mid;
        else l=mid;
    }
    if(ask(0,0,r,n)==1 && ask(r,0,n,n)==1) return r;
    else return -1;
}
int testy(int l, int r) {
    while(l+1<r) {
        int mid = (l+r)/2;
        if(ask(0,0,n,mid)>=1) r=mid;
        else l=mid;
    }
    if(ask(0,0,n,r)==1 && ask(0,r,n,n)==1) return r;
    else return -1;
}
rect sol(int x1, int y1, int x2, int y2) {
    for(int i=16; i>=0; i--) {
        int s = 1<<i;
        //이거 순서가 엄청 중요하다!!
        if(x1+s<x2 && ask(x1+s,y1,x2,y2)) x1+=s;
        if(x2-s>x1 && ask(x1,y1,x2-s,y2)) x2-=s;
        if(y1+s<y2 && ask(x1,y1+s,x2,y2)) y1+=s;
        if(y2-s>y1 && ask(x1,y1,x2,y2-s)) y2-=s;
    }
    return rect(x1,y1,x2,y2);
}
int main() {
    scanf("%d",&n);
    rect r1, r2;
    int tmp = testx(0,n);
    if(tmp!=-1) {
        r1 = sol(0,0,tmp,n);
        r2 = sol(tmp,0,n,n);
    } else {
        tmp = testy(0,n);
        r1 = sol(0,0,n,tmp);
        r2 = sol(0,tmp,n,n);
    }
    printf("! %d %d %d %d %d %d %d %d\n",r1.x1+1,r1.y1+1,r1.x2,r1.y2,r2.x1+1,r2.y1+1,r2.x2,r2.y2);
    fflush(stdout);
    return 0;
}

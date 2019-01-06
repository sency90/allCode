#include <cstdio>
using namespace std;
int main() {
    int w,h;
    scanf("%d%d",&w,&h);
    int u,d,u2,d2;
    scanf("%d%d%d%d",&u,&d,&u2,&d2);
    for(int i=h; i>=0; i--) {
        w+=i;
        if(i==d) {
            w-=u;
            if(w<0) w=0;
        }
        if(i==d2) {
            w-=u2;
            if(w<0) w=0;
        }
    }
    printf("%d\n", w);
    return 0;
}

#include <cstdio>
using namespace std;
inline int f(int x, int y) {
    if((x&1)&&(y&1)) return 1;
    else if((x&1)&&!(y&1)) return 2;
    else if(!(x&1)&&(y&1)) return 3;
    else return 4;
}
int main() {
    int n;
    scanf("%d", &n);
    puts("YES");
    for(int i=0; i<n; i++) {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n", f(x2,y2));
    }
    return 0;
}

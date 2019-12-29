#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int main() {
    int tc; scanf("%d",&tc);
    while(tc--) {
        int a,b,c,r;
        scanf("%d%d%d%d",&a,&b,&c,&r);

        int x=c-r, y=c+r;
        if(a>b) swap(a,b);
        if(y<=a || x>=b) printf("%d\n", b-a);
        else if(x<=a && y<=b) printf("%d\n", b-y);
        else if(a<=x && y<=b) printf("%d\n", x-a+b-y);
        else if(a<=x && b<=y) printf("%d\n", x-a);
        else printf("0\n");
    }
    return 0;
}

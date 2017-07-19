#include <iostream>
using namespace std;
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n,m;
        scanf("%d%d",&n,&m);
        n-=2; m-=2;
        int a=(n+2)/3, b=(m+2)/3;
        a=(a==0)?1:a;
        b=(b==0)?1:b;
        printf("%d\n", a*b);
    }
    return 0;
}


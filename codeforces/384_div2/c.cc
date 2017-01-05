#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    if(n==1) puts("-1");
    else if(n==2) puts("2 3 6");
    else if(n%2 == 1) printf("%d %d %d\n",n,n+1,n*(n+1));
    else printf("%d %d %d\n",n,n+2,n*(n+2)/2);
    return 0;
}

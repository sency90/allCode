#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    if(n%2==0) {
        printf("%d\n", n/2);
        int x=n/2;
        for(int i=0; i<x; i++) printf("2 ");
    } else if(n==3) {
        puts("1");
        puts("3");
    } else {
        int x=n-3;
        printf("%d\n", 1+x/2);
        int y=x/2;
        for(int i=0; i<y; i++) printf("2 ");
        printf("3");
    }
    return 0;
}

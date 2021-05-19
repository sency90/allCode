#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a==b && b==c) {
        printf("%d", 10000+a*1000);
    } else if(a!=b && b!=c && c!=a) {
        a=max(max(a,b),c);
        printf("%d", a*100);
    } else {
        if(b==c) a=b;
        printf("%d", 1000+a*100);
    }
}

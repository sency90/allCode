#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    if(n>=90) puts("A");
    else if(n>=70) puts("B");
    else if(n>=40) puts("C");
    else if(n>=0) puts("D");
    return 0;
}

#include <stdio.h>
short f(int a) {
    short m, c;
    m = a>1? (a%3 + f(a/3)+1) : 0;
    c = a>1? (a%2 + f(a/2)+1) : 0;
    return c<m? c:m;
}
int main() {
    int n; scanf("%d",&n);
    printf("%hd",f(n));
    return 0;
}

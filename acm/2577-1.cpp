#include <stdio.h>
int cnt[10];
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a = a*b*c;
    while(a!=0) {
        cnt[a%10]++;
        a/=10;
    }
    for(int i=0; i<10; i++) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}

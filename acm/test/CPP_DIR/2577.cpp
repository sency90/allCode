#include <stdio.h>
#include <cstring>
using namespace std;
int cnt[10];
void f(int x) {
    while(x!=0) {
        cnt[x%10]++;
        x/=10;
    }
}
int main() {
    int a, b, c;
    memset(cnt, 0, sizeof(cnt));
    scanf("%d %d %d", &a, &b, &c);
    a = a*b*c;
    f(a);
    for(int i=0; i<10; i++) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}

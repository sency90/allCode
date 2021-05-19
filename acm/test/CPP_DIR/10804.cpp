#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    char a[21], f, t;
    for(int i=0; i<21; i++) {
        a[i] = i;
    }
    for(int i=0; i<10; i++) {
        scanf("%hhd %hhd", &f, &t);
        reverse(a+f, a+t+1);
    }
    for(int i=1; i<=20; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

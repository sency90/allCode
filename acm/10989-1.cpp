#include <stdio.h>
int x[10001], d, n;
int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &d);
        x[d]++;
    }
    for(int i=0; i<10001; i++) {
        for(int j=0; j<x[i]; j++) {
            printf("%d\n", i);
        }
    }
}

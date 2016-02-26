#include <stdio.h>
int main() {
    char a[101], b[101];
    int t, sum; scanf("%d", &t);
    while(t--) {
        sum = 0;
        scanf("%s %s", a, b);
        for(int i=0; a[i]; i++) {
            if(a[i] == b[i]) continue;
            sum++;
        } printf("Hamming distance is %d.\n", sum);
    } return 0;
}

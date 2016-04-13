#include <stdio.h>
int num[100];
int main() {
    int n, in, f=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &in);
        while(num[f] != 0) {
            f = (f+1)%n;
        }
        num[f] = in;
        f = (num[f]+f)%n;
    }
    printf("%d\n", n);
    for(int i=0; i<n; i++) printf("%d ", num[i]);
    return 0;
}

#include <stdio.h>
int main() {
    int n, min=2000, t;
    scanf("%d", &n);
    for(int i=0; i<=n; i+=3) {
        for(int j=0; j<=n; j+=5) {
            if(i+j == n) {
                if(min > (t=i/3+j/5)) {
                    min = t;
                }
            }
        }
    }
    printf("%d", min==2000?-1:min);
    return 0;
}

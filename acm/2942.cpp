#include <stdio.h>
#define min(a,b) (a<b?a:b)

int main() {
    int r, g, m;
    scanf("%d %d", &r, &g);

    m = min(r,g);
    for(int i=1; i*i<=m; i++)  {
        if(r % i) continue;
        if(0 == g % i) {
            printf("%d %d %d\n", i, r/i, g/i);
        }
        if(0 == g%(r/i) && r/i!=i) {
            printf("%d %d %d\n", r/i, i, g/(r/i));
        }
    }

    return 0;
}

#include <stdio.h>
int main() {
    int a, b, sa, sb;
    int n; scanf("%d",&n);
    while(n--) {
        sa=0; sb=0;
        for(int i=0; i<9; i++) {
            scanf("%d %d", &a, &b);
            sa += a;
            sb += b;
        }
        if(sa > sb) printf("Yonsei\n");
        else printf("Korea\n");
    }
}

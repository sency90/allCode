#define ASSERT(x) if(!(x)) while(true);
#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int x1, y1, x2, y2;
    int n;
    int cx, cy, r;
    int cnt = 0;

    for(int i=0; i<T; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &n);

        for(int j=0; j<n; j++) {
            scanf("%d %d %d", &cx, &cy, &r);
            if((cx-x1)*(cx-x1)+(cy-y1)*(cy-y1) <= r*r) {
                cnt++;
                if((cx-x2)*(cx-x2)+(cy-y2)*(cy-y2) <= r*r) {
                    cnt--;
                }
            }
            else if((cx-x2)*(cx-x2)+(cy-y2)*(cy-y2) <= r*r) {
                cnt++;
                if((cx-x1)*(cx-x1)+(cy-y1)*(cy-y1) <= r*r) {
                    cnt--;
                }
            }
        }
        printf("%d\n", cnt);
        cnt = 0;
    }

    return 0;
}

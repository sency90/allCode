#include <stdio.h>
int main() {
    char c, prev, max, cnt;
    for(int i=0; i<3; i++) {
        cnt = 0; max = 1; prev = 0;
        while((c=getchar())&48 c!=EOF) {
            if(prev == c) cnt++;
            else {
                if(max < cnt) max = cnt;
                cnt = 1;
            }
            prev = c;
        }
        if(max < cnt) max = cnt;
        printf("%d\n", max);
    }
    return 0;
}

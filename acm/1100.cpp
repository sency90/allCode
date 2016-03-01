#include <stdio.h>
int main() {
    signed char c, cnt = 0, res = 0, i=8;
    while(i--) {
            while((c = getchar())!='\n' && c!=EOF) {
                        if(cnt++ % 2 == 0 && c == 'F') res++;
                    } cnt++;
        } printf("%hhd\n", res);
    return 0;
}

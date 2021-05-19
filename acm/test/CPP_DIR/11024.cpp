#include <stdio.h>
int main() {
    int t, sum=0, x=0;
    char c;
    scanf("%d", &t); getchar();
    while(t--) {
        x = 0;
        sum = 0;
        while((c = getchar())!='\n' && c!='\r' && c!=EOF) {
            if(c == ' ') {
                sum += x;
                x=0;
            } else x = x*10 + (c-'0');
        }
        sum += x;
        printf("%d\n", sum);
    } return 0;
}

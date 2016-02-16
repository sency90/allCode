#include <stdio.h>
int main() {
    char c, cnt=0;
    while((c=getchar())!='\n' && c!=EOF) cnt++;
    printf("%hhd\n", cnt);
    return 0;
}

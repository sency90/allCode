#include <stdio.h>
int main() {
    int cnt = 0;
    char c;
    while((c=getchar())!='\n' && c!=EOF) {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') cnt++;
    }
    printf("%d", cnt);
    return 0;
}

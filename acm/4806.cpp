#include<stdio.h>
int main() {
    int cnt = 0;
    char c;
    while((c=getchar())!=EOF) {
        if(c=='\n'||c=='\r') cnt++;
    }
    printf("%d", cnt);
    return 0;
}

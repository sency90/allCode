#include <stdio.h>
#define R 26
char chg(int a) {
    return (char)a+'A';
}

int main() {
    int a, b, t;
    char x;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &a, &b);
        getchar();
        while((x=getchar())!='\n' && x!='\r' && x!=' ' && x!=EOF) {
            printf("%c", chg((a*(x-'A')+b)%R));
        } printf("\n");
    }
    return 0;
}

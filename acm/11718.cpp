#include <stdio.h>
int main() {
    char c = 0;
    while(c!=EOF) {
        while((c = getchar())!='\n' && c!=EOF) printf("%c", c);
        printf("\n");
    }
    return 0;
}

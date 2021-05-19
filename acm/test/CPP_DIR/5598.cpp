#include <stdio.h>
int main() {
    char c;
    while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
        if(c <= 'C') c+=26;
        printf("%c", c-3);
    } return 0;
}

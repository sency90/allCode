#include <stdio.h>
int main() {
    char c;
    int i=0;
    while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
        if(i>0) {
            i--;
            continue;
        }
        if(c=='a' || c=='i' || c=='o' || c=='u' || c=='e') {
            i = 2;
        }
        printf("%c", c);
    }
    return 0;
}

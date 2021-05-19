#include <stdio.h>
#include <ctype.h>
int main() {
    char c;
    while((c=getchar())!=EOF && c!='\n' && c!='\r') {
        if(isupper(c)) putchar(c-'A'+'a');
        else putchar(c-'a'+'A');
    }
    return 0;
}

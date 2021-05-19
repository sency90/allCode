#include <stdio.h>
#include <ctype.h>
char rot13( char c ) {
    if(isupper(c)) {
        if(c<='M') c+=13;
        else c-=13;
    } else {
        if(c<='m') c+=13;
        else c-=13;
    }
    return c;
}
int main() {
    char c, str[101], i=0;
    while((c=getchar())!='\n' && c!=EOF) {
        if(isalpha(c)) str[i++] = rot13(c);
        else str[i++] = c;
    }
    str[i]='\0';
    printf("%s\n", str);
    return 0;
}

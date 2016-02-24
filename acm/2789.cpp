#include <stdio.h>
bool canPrint(char c) {
    switch(c) {
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'G':
        case 'I':
        case 'M':
        case 'R':
            return false;
        default:
            return true;
    }
}
int main() {
    char c;
    while((c=getchar())!='\n' && c!=EOF) {
        if(canPrint(c)) printf("%c", c);
    }
    return 0;
}

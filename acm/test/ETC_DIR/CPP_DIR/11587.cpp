#include <stdio.h>
#include <cstring>
using namespace std;
char str[1000][1001];
char comp[1001];
char f(char x) {
    switch(x) {
        case 'a': case 'b': case 'c': return '2';
        case 'd': case 'e': case 'f': return '3';
        case 'g': case 'h': case 'i': return '4';
        case 'j': case 'k': case 'l': return '5';
        case 'm': case 'n': case 'o': return '6';
        case 'p': case 'q': case 'r': case 's': return '7';
        case 't': case 'u': case 'v': return '8';
        default: return '9';
    }
}
int main() {
    bool ansNever = false;
    int n, cnt=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", str[i]);
    }
    scanf("%s", comp);
    int complen = strlen(comp);
    for(int i=0; i<n; i++) {
        int j=0;
        int len = strlen(str[i]);
        if(len != complen) continue;

        for(; j<len; j++) {
            if(f(str[i][j])!=comp[j]) {
                if(comp[j]=='1') ansNever = true;
                break;
            }
        }
        if(ansNever) {
            puts("0");
            return 0;
        }
        if(j==len) cnt++;
    }
    printf("%d", cnt);
    return 0;
}

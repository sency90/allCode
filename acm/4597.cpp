#include <stdio.h>
int main() {
    char c;
    int cnt;
    while(true) {
        cnt = 0;
        while((c=getchar())!='e' && c!='o' && c!='\n' && c!='\r' && c!=EOF) {
            if(c=='#') return 0;
            if(c=='1') cnt++;
            printf("%c", c);
        }
        if(c=='\n' || c=='\r') continue;
        if(c==EOF) return 0;
        if(c=='e') {
            if(cnt%2 == 0) puts("0");
            else puts("1");
        } else {
            if(cnt%2 == 0) puts("1");
            else puts("0");
        }
    }
    return 0;
}

#include <stdio.h>
int main() {
    char c;
    int ind=0;
    bool bOpen;
    freopen("input.txt", "r", stdin);
    while((c=getchar())!='\n' && c!=EOF && c!='\r') {
        if(c=='{') {
            bOpen = true;
            for(int i=0; i<ind; i++) putchar(' ');
            puts("{");
            ind += 2;
            continue;
        } else if(c=='}') {
            ind-=2;
            if(!bOpen) puts("");
            for(int i=0; i<ind; i++) putchar(' ');
            putchar('}');
        } else if(c==',') {
            bOpen = true;
            puts(",");
            continue;
        } else {
            if(bOpen) {
                for(int i=0; i<ind; i++) putchar(' ');
            }
            putchar(c);
        }
        bOpen = false;
    }
    return 0;
}

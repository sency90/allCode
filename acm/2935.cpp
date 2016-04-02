#include <stdio.h>
int main() {
    char c;
    int cnt[2]={0,0}, i=0;
    bool isAdd;
    while((c=getchar())!=EOF) {
        if(c=='0') cnt[i]++;
        if(c=='*') {
            isAdd = false;
            i++;
        } else if(c=='+') {
            isAdd = true;
            i++;
        }
    }
    if(isAdd) {
        int b = cnt[0];
        int l = cnt[1];
        if(b < l) {
            b = l;
            l = cnt[0];
        }
        for(int i=b; i>=0; i--) {
            if(i==b && i==l) putchar('2');
            else if(i==b) putchar('1');
            else if(i==l) putchar('1');
            else putchar('0');
        }
    } else {
        cnt[0] += cnt[1];
        putchar('1');
        for(int i=0; i<cnt[0]; i++) {
            putchar('0');
        }
    }
}

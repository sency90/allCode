#include <stdio.h>
#include <string.h>
#define max(a,b) (a>b?a:b)
int chk[9];
int main() {
    int t;
    char str[8];
    for(int i=0; i<9; i++) chk[i]=0;
    scanf("%s", str);
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        t = str[i]-'0';
        if(t==6 || t==9) chk[6]++;
        else chk[t]++;
    }

    if(chk[6]%2 == 0) chk[6]/=2;
    else chk[6] = chk[6]/2+1;

    int m=0;
    for(int i=0; i<9; i++) {
        m = max(m, chk[i]);
    }
    printf("%d", m);
    return 0;
}

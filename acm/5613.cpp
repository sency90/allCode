#include <stdio.h>
int main() {
    char c;
    int chk=4, res=0, x;
    while(true) {
        scanf("%d %c", &x, &c);
        if(chk==1) res /= x;
        else if(chk==2) res *= x;
        else if(chk==3) res -= x;
        else if(chk==4) res += x;

        if(c=='=') break;
        else if(c=='+') chk = 4;
        else if(c=='-') chk = 3;
        else if(c=='*') chk = 2;
        else if(c=='/') chk = 1;
    }
    printf("%d", res);
    return 0;
}

#include <stdio.h>
int main() {
    int t, n;
    char c;
    bool zf;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) {
        zf = false;
        scanf("%d ", &n);
        while((c=getchar())!='\n'&&c!=EOF&&c!='\r') {
            if(c=='c') n++;
            else n--;
            if(n==0) zf = true;
        }
        printf("Data Set %d:\n", i);
        if(zf) puts("0");
        else printf("%d\n", n);
        puts("");
    }
    return 0;
}

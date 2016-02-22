#include <stdio.h>
char v[10003];
int main() {
    int i = 2, cnti=0, cntj=0;
    v[0] = v[1] = 0;
    while((v[i]=getchar())!='\n' && v[i]!=EOF && v[i]!='\r' && v[i]!=' ') {
        if(v[i]=='I') {
            if(v[i-1]=='O') {
                if(v[i-2]=='I') cnti++;
                else if(v[i-2]=='J') cntj++;
            }
        }
        i++;
    }
    printf("%d\n%d\n", cntj, cnti);
    return 0;
}

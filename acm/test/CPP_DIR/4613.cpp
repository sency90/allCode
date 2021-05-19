#include <stdio.h>
int main() {
    char c;;
    int i, sum;
    while(true) {
        i=0;
        sum = 0;
        while((c=getchar())!='\n' && c!='\r' && c!='#') {
            i++;
            if(c==' ') continue;
            sum += (c-'A'+1)*i;
        }
        if(c=='#') return 0;
        printf("%d\n", sum);
    }
    return 0;
}

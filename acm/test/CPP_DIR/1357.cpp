#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main() {
    int i=0, j=0, k, fj, sj, sum, len;
    char c, x[2][5], str[6];
    for(k=0; k<2; k++, i++) {
        fj=j;
        j=0;
        while((c=getchar())!=' ' && c!='\n' && c!='\r' && c!=EOF) {
            x[i][j++]=c;
        }
    }
    sj = j;

    reverse(x[0], x[0]+fj);
    reverse(x[1], x[1]+sj);
    sum = atoi(x[0]);
    sum += atoi(x[1]);
    sprintf(str, "%d", sum);

    len = strlen(str);
    reverse(str, str+len);
    sum = atoi(str);
    printf("%d", sum);
    return 0;
}

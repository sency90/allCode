#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char x[8], y[8], maxx[8], minx[8], maxy[8], miny[8];
    scanf("%s%s", x, y);
    int len1 = strlen(x);
    int len2 = strlen(y);

    for(int i=0; i<len1; i++) {
        maxx[i] = x[i];
        minx[i] = x[i];
        if(x[i]=='5') maxx[i] = '6';
        else if(x[i]=='6') minx[i] = '5';
    }
    for(int i=0; i<len2; i++) {
        maxy[i] = y[i];
        miny[i] = y[i];
        if(y[i]=='5') maxy[i] = '6';
        else if(y[i]=='6') miny[i] = '5';
    }
    int max = atoi(maxx)+atoi(maxy);
    int min = atoi(minx)+atoi(miny);
    printf("%d %d", min, max);
    return 0;
}

#include <stdio.h>

int main() {
    int digit, r;
    int i, j;
    char result[18];
    scanf("%d", &digit);

    char a[8][3] = {'0','0','0', '1','0','0', '0','1','0', '1','1','0', '0','0','1', '1','0','1', '0','1','1', '1','1','1'};

    i = 0;
    while(true) {
        r = digit % 10;
        for(j=0; j<3; j++) {
            result[i++] = a[r][j];
        }

        if(digit < 10) break;
        digit /= 10;
    }

    bool canPrint = false;
    for(j=i-1; j>=0; j--) {
        if(result[j] != '0') {
            canPrint = true;
            printf("%c", result[j]);
        }
        else if(canPrint) printf("%c", result[j]);
    }
    if(!canPrint) printf("0");
    printf("\n");

    return 0;
}

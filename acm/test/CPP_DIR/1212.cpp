#include <stdio.h>

char a[8][3] = {'0','0','0', '0','0','1', '0','1','0', '0','1','1', '1','0','0', '1','0','1', '1','1','0', '1','1','1'};

int main() {
    char c;
    int digit;
    int j;

    bool canPrintZero = false;
    while((c = getchar())!='\n') {
        digit = (int)c - 48;
        if(!canPrintZero) {
            for(j=0; j<3; j++) {
                if(a[digit][j] == '1') {
                    printf("%c", a[digit][j]);
                    canPrintZero = true;
                }
                else if(canPrintZero) {
                    printf("%c", a[digit][j]);
                }
            }
        }
        else {
            for(j=0; j<3; j++) {
                printf("%c", a[digit][j]);
            }
        }
    }

    if(!canPrintZero) printf("0");
    printf("\n");

    return 0;
}

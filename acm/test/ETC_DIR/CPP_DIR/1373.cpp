#include <stdio.h>

char input[1000000];
int cnt, startIdx;

int main() {

    cnt = -1;
    while((input[++cnt] = getchar())!='\n');

    startIdx = cnt % 3;
    if(cnt == 1) {
        printf("%c", input[0]);
        return 0;
    }

    if(startIdx == 1) {
        printf("1");
    } else if(startIdx == 2) {
        if('0' == input[1]) printf("2");
        else printf("3");
    }

    while(startIdx < cnt) {
        if('0' == input[startIdx++]) {
            if('0' == input[startIdx++]) {
                if('0' == input[startIdx++]) {
                    printf("0");
                } else printf("1");
            } else if('0' == input[startIdx++]) {
                printf("2");
            } else printf("3");
        } else if('0' == input[startIdx++]) {
            if('0' == input[startIdx++]) {
                printf("4");
            } else printf("5");
        } else if('0' == input[startIdx++]) {
            printf("6");
        } else printf("7");
    }

    return 0;
}

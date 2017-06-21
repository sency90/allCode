#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
    int i = 0;
    int cnt = 0;
    char temp[1000003];
    fgets(temp, sizeof(temp), stdin);

    if(temp[strlen(temp)-1]=='\n') temp[strlen(temp)-1] = '\0';
    else temp[strlen(temp)] = '\0';

    for (i; temp[i] != '\0';) {
        if (temp[i] == 32) {
            i++;
        }
        else {
            break;
        }
    }
    for (; temp[i] != '\0'; i++) {
        if (temp[i] != 32 && temp[i]!='\n') {//////////////요기@
            if (temp[i + 1] == 32 || temp[i + 1] == '\0') {
                cnt++;
            }
        }
    }



    printf("%d", cnt);

    return 0;
}

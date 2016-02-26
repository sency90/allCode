#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char eq[10], *p;
    int n, sum;
    bool isIn;
    scanf("%d", &n);
    while(n--) {
        scanf("%s", eq);
        sum = 0;
        isIn = false;
        for(p=strtok(eq,"+"); p; p=strtok(0,"+")) {
            if(!strcmp(p,"P=NP")) {
                printf("skipped\n");
                isIn = true;
                break;
            }
            sum += atoi(p);
        }
        if(isIn) continue;
        printf("%d\n", sum);
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char s[9], f[9], *p;
    int start[3], end[3], i;
    bool carry1=false, carry2=false;
    scanf("%s %s", s, f);
    for(i=0, p=strtok(s,":"); p; i++, p=strtok(0,":")) {
        start[i] = atoi(p);
    }
    for(i=0, p=strtok(f,":"); p; i++, p=strtok(0,":")) {
        end[i] = atoi(p);
    }

    end[0]+=23-start[0];
    end[1]+=59-start[1];
    end[2]+=60-start[2];
    if(end[2] >= 60) {
        end[2]-=60;
        carry2 = true;
    }
    if(carry2) end[1]+=1;
    if(end[1] >= 60) {
        end[1]-=60;
        carry1 = true;
    }
    if(carry1) end[0]+=1;
    if(end[0] >= 24) end[0]-=24;

    printf("%02d:%02d:%02d", end[0], end[1], end[2]);
    return 0;
}

#include <stdio.h>
int main() {
    int sh,sm,ss,eh,em,es;
    scanf("%d:%d:%d", &sh, &sm, &ss);
    scanf("%d:%d:%d", &eh, &em, &es);
    if(sh==eh && sm==em && ss==es) {
        puts("24:00:00");
        return 0;
    }
    eh+=23; em+=59; es+=60;
    es-=ss;
    if(es>=60) {
        em++;
        es-=60;
    }
    em-=sm;
    if(em>=60) {
        eh++;
        em-=60;
    }
    eh-=sh;
    if(eh>=24) {
        eh-=24;
    }
    printf("%02d:%02d:%02d",eh,em,es);
    return 0;
}

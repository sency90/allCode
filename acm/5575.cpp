#include <stdio.h>
int main() {
    int sh, sm, ss, eh, em, es;
    for(int i=0; i<3; i++) {
        scanf("%d %d %d", &sh, &sm, &ss);
        scanf("%d %d %d", &eh, &em, &es);
        eh+=23; em+=59; es+=60;
        if((es-=ss) >= 60) {
            es-=60;
            em+=1;
        }
        if((em-=sm) >= 60) {
            em-=60;
            eh+=1;
        }
        eh = eh-sh-24;
        printf("%d %d %d\n", eh, em, es);
    }
    return 0;
}

#include <stdio.h>
int main() {
    int d; bool v[31]= {false,};
    for(int i=0; i<28; i++) {
        scanf("%d", &d);
        v[d] = true;
    } for(int i=1; i<=30; i++) {
        if(!v[i]) printf("%d\n", i);
    } return 0;
}

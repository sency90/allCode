#include <stdio.h>
int main() {
    int s[2]={0,}, d, m;
    for(int j=0; j<2; j++) {
        for(int i=0; i<4; i++) {
            scanf("%d", &d);
            s[j] += d;
        }
    }
    if(s[0] > s[1]) m = s[0];
    else m = s[1];
    printf("%d", m);
}

#include <stdio.h>
int main() {
    int pi[] = {1, 10, 100};
    int x=0, y=0, d;
    for(int i=0; i<3; i++) {
        scanf("%1d", &d);
        x += d*pi[i];
    }
    for(int i=0; i<3; i++) {
        scanf("%1d", &d);
        y += d*pi[i];
    }
    if(x>y) printf("%d", x);
    else printf("%d", y);
}

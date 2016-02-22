#include <stdio.h>
struct Person{
    int w, h, o;
}p[50];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &p[i].w, &p[i].h);
        p[i].o = n;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            if(p[i].w>=p[j].w || p[i].h>=p[j].h) p[i].o--;
        }
    }

    for(int i=0; i<n; i++) printf("%d ", p[i].o);
    return 0;
}

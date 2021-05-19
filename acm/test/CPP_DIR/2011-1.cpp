#include <stdio.h>
#include <string.h>
#define RND 1000000
char v[5001], c;
int d[5001], i=0;
int main() {
    memset(d, 0, sizeof(d));
    d[0] = 1;
    v[0] = 0;
    while((c = getchar())!='\n' && c!=EOF) {
        v[++i] = c-48;
        if(v[i] >= 1) d[i] = (d[i] + d[i-1]) % RND;
        if(i == 1) continue;
        if(v[i-1] == 0) continue;
        if(v[i-1] == 1 || (v[i-1]==2 && v[i]<=6)) {
            d[i] = (d[i] + d[i-2]) % RND;
        }
    }
    printf("%d", d[i]);
}

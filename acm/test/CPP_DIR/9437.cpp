#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int n, p[4], d;
    while(true) {
        scanf("%d", &n);
        if(n == 0) return 0;
        scanf("%d", &d);
        p[0] = d;
        p[1] = n-p[0]+1;
        if(p[0]%2 == 0) {
            p[2] = p[0]-1;
            p[3] = p[1]+1;
        } else {
            p[2] = p[0]+1;
            p[3] = p[1]-1;
        }
        sort(p, p+4);
        for(int i=0; i<4; i++) {
            if(p[i] == d) continue;
            printf("%d ", p[i]);
        } puts("");
    }
    return 0;
}

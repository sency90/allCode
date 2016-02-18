#include <stdio.h>
#include <string.h>
short v[1000], cache[1000], cap[1000], n;
short f( short idx ) {
    if(idx == 0) return cache[idx] = 1; //base case
    if(cache[idx] > 0) return cache[idx];

    if(v[idx] > cap[idx-1]) {
        cap[idx] = v[idx];
        return cache[idx] = f(idx-1) + 1;
    } else return cache[idx] = f(idx-1);
}
int main() {
    memset(cache, 0, sizeof(cache));
    memset(cap, 0, sizeof(cap));
    scanf("%hd", &n);
    for(short i=n-1; i>=0; i--) {
        scanf("%hd", &v[i]);
    }
    cap[0] = v[0];
    printf("%hd", f(n-1));
    return 0;
}

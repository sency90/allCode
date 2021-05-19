#include <stdio.h>
int chg(int x, int rnd) {
    int res = 0;
    while(x!=0) {
        res+=x%rnd;
        x/=rnd;
    } return res;
}
int main() {
    int tmp;
    for(int i=2992; i<10000; i++) {
        tmp = chg(i,10);
        if(tmp==chg(i,12) && tmp==chg(i,16)) printf("%d\n", i);
    }
    return 0;
}

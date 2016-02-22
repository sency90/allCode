#include <stdio.h>
#include <algorithm>
using namespace std;
int d[4], t;
int rule() {
    bool light = false;
    int curRule = 5;
    sort(d, d+4);
    for(int i=0; i<3; i++) {
        if(d[i] == d[i+1]) {
            t = d[i];
            if(light && i==2) curRule = 0;
            else curRule--;
        } else if(i==1 && curRule==4) light=true;
    }
    if(curRule==0) curRule=3;
    else if(curRule <= 3) curRule--;
    return curRule;
}
int main() {
    int n, i, curAmt, maxAmt=0, x;
    scanf("%d", &n);
    while(n--) {
        for(i=0; i<4; i++) scanf("%d", &d[i]);
        x = rule();
        switch(x) {
            case 1:
                curAmt = 50000+d[0]*5000;
                break;
            case 2:
                curAmt = 10000+d[1]*1000;
                break;
            case 3:
                curAmt = 2000+(d[0]+d[2])*500;
                break;
            case 4:
                curAmt = 1000+t*100;
                break;
            case 5:
                curAmt = d[3]*100;
                break;
        }
        if(maxAmt < curAmt) maxAmt = curAmt;
    }
    printf("%d\n", maxAmt);
    return 0;
}

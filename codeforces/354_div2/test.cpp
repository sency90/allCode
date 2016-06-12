#include <cstdio>
#include <climits>
using namespace std;
char cwr(char s, int rotateCnt) {
    rotateCnt %= 4;
    if(rotateCnt==0) return s;
    if(rotateCnt==1) return ((s&1)<<3)+(s>>1);
    if(rotateCnt==2) return ((s&3)<<2)+(s>>2);
    else return ((s&7)<<1)+(s>>3);
}
char chkState(char x, char y) {
    return cwr(x,2)&y;
}
int main() {
    printf("%hhd",chkState(1,4));
    return 0;
}

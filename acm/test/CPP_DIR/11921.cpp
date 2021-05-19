#include <stdio.h>
static char buf[0x80000];
static int cur=0;
static int chnum=0;
static inline int scan() {
    if(cur == chnum) {
        chnum = (int)fread(buf,sizeof(buf[0]),sizeof(buf),stdin);
        cur=0;
    } return buf[cur++];
}
static inline int scanInt() {
    int x=0, c=scan();
    while(c&32) { x=x*10+(c-'0'); c=scan();}
    return x;
}
int main() {
    int n=scanInt();
    printf("%d\n", n);
    long long sum=0LL;
    while(n--) sum+=scanInt();
    printf("%lld", sum);
    return 0;
}

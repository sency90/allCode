#include <stdio.h>
int main() {
    bool c = false;
    int h,m,s,hh,mm,ss;
    scanf("%d:%d:%d%d:%d:%d", &h,&m,&s,&hh,&mm,&ss);
    if(h==hh && m==mm && s==ss) {
        puts("24:00:00");
        return 0;
    }
    hh+=23; mm+=59; ss+=60;
    s=ss-s;
    if(s >= 60) {
        s -= 60;
        c = true;
    }
    m=mm-m+(c?1:0);
    if(m >= 60) {
        m-=60;
        c = true;
    } else c = false;
    h=hh-h+(c?1:0);
    if(h >= 24) h-=24;
    printf("%02d:%02d:%02d",h,m,s);
    return 0;
}

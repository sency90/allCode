#include <stdio.h>
char*c[]={"Sun","Mon","Tues","Wednes","Thurs","Fri","Satur"};
int main(){
    int x, y;
    scanf("%d%d",&y,&x);
    printf("%sday",(c[("0400351362402"[x]+y)%7]));
    return 0;
}

#include <stdio.h>
int main(){
    char a,b;
    while(scanf("%hhd%hhd",&a,&b)!=EOF) {
        if(a+b == 0) return 0;
        else printf("%hhd\n", a+b);
    } return 0;
}

#include <stdio.h>
int main(){
    int n;
    char a,b;
    scanf("%d", &n);
    while(n--) {
        scanf("%hhd%hhd",&a,&b);
        printf("%hhd\n", a+b);
    }
    return 0;
}

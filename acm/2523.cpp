#include <stdio.h>
int n;
void f(int x) {
    int t;
    if(x==n) t = 1;
    else t = 2;
    for(int i=0; i<t; i++) {
        for(int j=0; j<x; j++) {
            printf("*");
        }
        puts("");
        if(x==n) return;
        if(i==0) f(x+1);
    }
    return;
}
int main() {
    scanf("%d", &n); f(1);
}

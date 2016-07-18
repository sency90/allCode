#include <stdio.h>
#include <algorithm>
using namespace std;
char d[61][61][61], a[3], n;
char f(char x, char y, char z) {
    if(x<0) x=0;
    if(y<0) y=0;
    if(z<0) z=0;
    if(x==0 && y==0 && z==0) return 0;
    if(d[x][y][z]>0) return d[x][y][z];
    return d[x][y][z] = min({f(x-9,y-3,z-1),f(x-9,y-1,z-3),f(x-3,y-9,z-1),f(x-3,y-1,z-9),f(x-1,y-3,z-9),f(x-1,y-9,z-3)})+1;
}
int main() {
    scanf("%hhd", &n);
    for(int i=0; i<n; i++) scanf("%hhd", &a[i]);
    printf("%hhd", f(a[0],a[1],a[2]));
    return 0;
}

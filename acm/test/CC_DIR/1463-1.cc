#include <stdio.h>
#include <algorithm>
using namespace std;
int d[1000001];
int f(int x) {
    if(x==1) return 0;
    if(d[x]>0) return d[x];
    if((x%3) == 0) return d[x] = min(f(x-1),f(x/3))+1;
    else if((x%2) == 0) return d[x] = min(f(x-1),f(x/2))+1;
    else return d[x]=f(x-1)+1;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", f(n));
    return 0;
}

#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int l, a, b, c, d;
    scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
    if(a%c==0) a/=c;
    else a=a/c+1;
    if(b%d==0) b/=d;
    else b=b/d+1;
    int t = l-max(a,b);
    if(t < 0) printf("0");
    else printf("%d", t);
    return 0;
}

#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int t,a,b,c,mx=0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &a, &b, &c);
        if(a==b && b==c) a = 10000+1000*a;
        else if(a!=b && b!=c && c!=a) {
            a = max(a, max(b,c))*100;
        } else {
            if(b==c) a=b;
            a = 1000+100*a;
        }
        if(mx < a) mx = a;
    }
    printf("%d", mx);
}

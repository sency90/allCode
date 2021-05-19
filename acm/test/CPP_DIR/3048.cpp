#include <stdio.h>
#include <algorithm>
using namespace std;
char a[27],b[27];
int main() {
    int alen, blen, t;
    scanf("%d %d ", &alen, &blen);
    if(alen) scanf("%s", a);
    if(blen) scanf("%s", b);
    scanf("%d",&t);
    if(t>=max(alen,blen)*2) t=max(alen,blen)*2-1;
    reverse(a, a+alen);
    for(int i=0; i<alen-t; i++) {
        if(a[i]) putchar(a[i]);
    }
    for(int i=0; i<t; i++) {
        if(b[i]) putchar(b[i]);
        if(a[alen-t+i]) putchar(a[alen-t+i]);
    }
    for(int i=t; i<blen; i++) {
        if(b[i]) putchar(b[i]);
    }
    return 0;
}

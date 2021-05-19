#include <stdio.h>
int chk(int x) {
    int sum = 0;
    while(x!=0) {
        sum+=x%10;
        x/=10;
    }
    return sum;
}
int main() {
    int l,d,x,mn=0x3f3f3f3f,mx=0;
    bool first = true;
    scanf("%d%d%d",&l,&d,&x);
    for(int i=l; i<=d; i++) {
        if(chk(i) == x) {
            if(first) mn = i;
            first = false;
            if(mx < i) mx = i;
        }
    }
    printf("%d\n%d\n",mn,mx);
    return 0;
}

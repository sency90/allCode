#include <stdio.h>
int f(int i) {
    int res = 1;
    for(int k=0; k<i; k++) res*=26;
    return res;
}
int main() {
    int i, sum, t, d;
    char c;
    scanf("%d", &t);
    getchar();
    while(t--) {
        sum = 0;
        i=2;
        while((c=getchar())!='-') {
            sum += ((int)(c-'A'))*f(i--);
        }
        scanf("%d", &d);
        if(d-sum < -100 || d-sum > 100) printf("not nice\n");
        else printf("nice\n");
        getchar();
    }
    return 0;
}

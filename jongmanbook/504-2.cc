//Brute Force
#include <stdio.h>
#define LIM 10000000
int fcNum[LIM+1];
int main() {
    int t,n,l,r;
    for(int i=1; i<=LIM; i++) {
        for(int j=i; j<=LIM; j+=i) {
            fcNum[j]++;
        }
    }
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n,&l,&r);
        int cnt = 0;
        for(int i=l; i<=r; i++) {
            if(fcNum[i] == n) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}

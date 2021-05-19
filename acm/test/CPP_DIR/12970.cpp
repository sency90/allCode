#include <stdio.h>
#include <cstring>
using namespace std;
bool isPrime[1001];
int main() {
    int n, k;
    scanf("%d%d",&n,&k);
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2; i*i<=k; i++) {
        for(int j=i*i; j<=k; j+=i) {
            isPrime[j] = false;
        }
    }
    if(isPrime[k]) 
    //for(int p=0; p<30; p++) {
    //for(int q=0; q<p*p-1; q++) {
    //n=p; k=q;
    printf("n:%d k:%d\t",n,k);
    if(k==0) {
        for(int i=0; i<n; i++) {
            putchar('B');
        }
        puts("");
        //continue;
        return 0;
    }
    for(int i=1; i*i<=k; i++) {
        if(k%i==0) {
            int y = k/i;
            if(i+y <= n) {
                for(int j=0; j<y; j++) putchar('A');
                for(int j=0; j<i; j++) putchar('B');
                for(int j=0; j<n-(y+i); j++) putchar('A');
                puts("");
                return 0;
                //continue;
            }
        }
    }
    puts("-1");
    //}
    //}
    return 0;
}

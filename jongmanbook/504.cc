#include <stdio.h>
const int LIM = 1000*1000*10;
int mnf[LIM+1], mnfpower[LIM+1];
int factors[LIM+1];
int main() {
    for(int i=2LL; i<=LIM; i++) mnf[i]=i;
    //the sieve of Eratosthenes
    mnf[0]=mnf[1]=-1;
    for(long long i=2LL; i*i<=LIM; i++) {
        if(mnf[i]==i) {
            for(long long j=i*i; j<=LIM; j+=i) {
                if(mnf[j]==j) mnf[j]=i;
            }
        }
    }
    factors[1] = 1;
    for(int i=2; i<=LIM; i++) {
        if(mnf[i]==i) {
            mnfpower[i] = 1;
            factors[i] = 2;
        } else {
            int p = mnf[i];
            int m = i/p;
            if(mnf[i] == mnf[m]) mnfpower[i] = mnfpower[m]+1;
            else mnfpower[i] = 1;
            factors[i] = (factors[m]/mnfpower[i])*(mnfpower[i]+1);
        }
    }
    int T,n,lo,hi,cnt;
    scanf("%d", &T);
    while(T--) {
        cnt=0;
        scanf("%d%d%d",&n,&lo,&hi);
        for(int i=lo; i<=hi; i++) {
            if(factors[i] == n) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}

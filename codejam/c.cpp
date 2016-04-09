#include <stdio.h>
#include <cmath>
#include <cstring>
#include <vector>
#define LIM 33333334
#define PRIME_IDX 2050944
using namespace std;
bool isP[LIM];
long long factor[10][16], mem[11], ans[11];
void initPrime() {
    memset(isP, true, sizeof(isP));
    isP[0]=false; isP[1]=false;
    for(long long i=2; i*i<=LIM; i++) {
        if(!isP[i]) continue;
        for(long long j=i*i; j<=LIM; j+=i) {
            isP[j] = false;
        }
    }
}
void initFactor() {
    for(int i=2; i<=9; i++) {
        factor[i][0] = 1;
        for(int j=1; j<=16; j++) {
            factor[i][j] = factor[i][j-1]*i;
        }
    }
}
int main() {
    int t, n, m;
    initPrime();
    initFactor();
    scanf("%d", &t);
    for(int z=1; z<=t; z++) {
        printf("Case #%d:\n", z);
        scanf("%d %d", &n, &m);
        if(m==0) continue;
        long long x = factor[2][n-1];
        int cnt = 0;
        for(long long i=x+1; i<2*x; i+=2) {
            long long tmp = i;
            vector<int> v;
            while(tmp!=0) {
                v.push_back(tmp%2);
                tmp/=2;
            }
            long long sum = 0;
            bool isPrime = false;
            for(int k=2; k<=10; k++) {
                ans[k]=0LL;
                if(k==10) {
                    sum = 0;
                    for(int j=v.size()-1; j>=0; j--) {
                        sum = sum*10 + v[j];
                    }
                } else {
                    sum = 0;
                    for(int j=0; j<v.size(); j++) {
                        sum += factor[k][j]*v[j];
                    }
                }

                if(sum >= LIM) {
                    bool isBrk = false;
                    for(long long j=2; j<=LIM && j*j<=sum; j++) {
                        if(isP[j]) {
                            if(sum%j==0) {
                                ans[k] = j;
                                isBrk = true;
                                break;
                            }
                        }
                    }
                    if(isBrk) {
                        mem[k] = sum;
                        continue;
                    } else {
                        isPrime = true;
                        break;
                    }
                } else if(isP[sum]) {
                    isPrime = true;
                    break;
                }
                mem[k] = sum;
            }
            if(isPrime) continue;

            for(int j=v.size()-1; j>=0; j--) {
                printf("%d", v[j]);
            }putchar(' ');
            for(int j=2; j<=10; j++) {
                if(ans[j]>0) printf("%lld ", ans[j]);
                else {
                    for(long long k=2; k*k<=mem[j]; k++) {
                        if(mem[j]%k == 0) {
                            printf("%lld ", k);
                            break;
                        }
                    }
                }
            }puts("");
            if(++cnt >= m) break;
        }
    }
    return 0;
}

#include <cstdio>
#include <cstring>
using namespace std;
bool prime[100001];
int d[10000], p[10000];
int main() {
    int n, x, k=0, cnt;
    scanf("%d", &n);
    memset(p, -1, sizeof(p));
    memset(prime, true, sizeof(prime));
    for(int i=2; i<=100000; i++) {
        if(prime[i]) p[k++] = i;
        for(int j=i*i; j<=100000; j+=i) {
            prime[j] = false;
        }
    }
    while(n--) {
        cnt = 0;
        memset(d, 0, sizeof(d));
        scanf("%d", &x);
        for(int i=0; p[i]<=x; i++) {
            //if(x%p[i]==0 && x/p[i]!=0) cnt++;
            if(p[i]==-1) break;
            if((x%p[i]==0) && (x/p[i]!=0) && x!=0) cnt++;
            while((x%p[i]==0) && (x/p[i]!=0) && x!=0) {
                x/=p[i];
                d[i]++;
            }
        }
        for(int i=0; i<=cnt; i++) {
            if(d[i] != 0) printf("%d %d\n", p[i], d[i]);
        }
    }
    return 0;
}

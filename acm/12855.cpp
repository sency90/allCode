#include <stdio.h>
#include <algorithm>
using namespace std;
long long x;
long long getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
long long a[100001];
long long b[100001];
int main() {
    int i, n, d;
    scanf("%d %d %lld", &n,&d,&x);
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
        if(i<d) b[i]=1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }

    long long p=a[0]*b[0];
    for(i=0; i<n; i++) {
        printf("%lld", a[i]*b[i]);
        if(b[i]==0) printf("%lld ", p);
        else if(p > a[i]) printf("%lld ", p);
        else {
            printf("%lld ", a[i]);
            p = a[i];
        }
    }
    return 0;
}


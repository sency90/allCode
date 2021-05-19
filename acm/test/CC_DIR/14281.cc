#include <cstdio>
using namespace std;
int v[51];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    long long cnt=0;
    while(true) { bool good = true;
        for(int i=1; i<n-1; i++) {
            if(v[i]*2 > v[i-1]+v[i+1]) {
                int goal=(v[i-1]+v[i+1])/2;
                cnt+=(v[i]-goal);
                v[i]=goal;
                good=false;
            }
        }
        if(good) break;
    }
    if(n<=2) cnt=0;
    printf("%lld", cnt);
    return 0;
}

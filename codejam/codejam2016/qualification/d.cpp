#include <stdio.h>
#include <deque>
using namespace std;
long long spow(int k, int c) {
    long long res = 1;
    for(int i=0; i<c; i++) res*=k;
    return res;
}
int main() {
    int t, k, c, s;
    scanf("%d", &t);
    for(int ii=1; ii<=t; ii++) {
        scanf("%d %d %d", &k, &c, &s);
        printf("Case #%d: ", ii);
        if(s <= k-c) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        long long x = spow(k,c-1);
        deque<long long> dq;
        for(long long i=0; i<k; i++) {
            dq.push_back(x*i+k/2+1);
            //printf("%lld ", x*i+1);
        }
        for(int i=0; i<s; i++) {
            printf("%lld ", dq.front()); dq.pop_front();
            if(++i>=s) continue;
            printf("%lld ", dq.back()); dq.pop_back();
        }
        puts("");
    }
}

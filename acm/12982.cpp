#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> v;
int main() {
    long long k, d, sum=0LL;
    scanf("%lld", &k);
    v.resize(k);
    for(int i=0; i<k; i++) {
        scanf("%lld", &d);
        sum+=d/k;
        v[i]=d%k;
    }
    sort(v.begin(), v.end());
    long long mn=0x3f3f3f3f;
    for(int i=0; i<k; i++) {
        if(mn>v[i]+(k-i-1)) mn = v[i]+k-i-1;
    }
    printf("%lld", mn+sum);
    return 0;
}

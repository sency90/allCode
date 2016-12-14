#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll v[100001];
bool cmp(int i, int j) {return i>j;}
int main() {
    int n,n1,n2;
    scanf("%d%d%d",&n,&n1,&n2);
    for(int i=0; i<n; i++) {
        scanf("%lld", &v[i]);
    }
    sort(v, v+n, cmp);
    if(n1>n2) swap(n1,n2);

    ll sum1=0LL, sum2=0LL;
    for(int i=0; i<n1; i++) sum1 += v[i];
    for(int i=n1; i<n1+n2; i++) sum2 += v[i];
    printf("%.8lf\n",((double)sum1/(double)n1)+((double)sum2/(double)n2));
    return 0;
}

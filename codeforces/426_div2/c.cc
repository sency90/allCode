#include <stdio.h>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
map<ll,int> s;
int main() {
    int n; scanf("%d", &n);
    for(ll i=1LL; i<=1000000LL; i++) s[i*i*i]=i;
    for(int i=0; i<n; i++) {
        ll a,b; scanf("%lld%lld",&a,&b);
        if(!s.count(a*b)) puts("No");
        else if(a*a%b) puts("No");
        else if(b*b%a) puts("No");
        else puts("Yes");
    }
    return 0;
}

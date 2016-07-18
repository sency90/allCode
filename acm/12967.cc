#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
map<int, int> d[2001][4];
int a[2001];
int gcd(int b, int l) {
    if(b<l) swap(b,l);
    if(b%l) return gcd(l, b%l);
    else return l;
}
int f(int n, int s, int k) {
    if(d[n][s].count(k)>0) return d[n][s][k];
    d[n][s][k]=0;
    int &ans = d[n][s][k];
    ans = 0;
    if(s==0) {
        if(k==1) return ans=1;
        else return ans=0;
    } else if(n==0) return ans=0;
    ans += f(n-1,s-1,k/gcd(a[n-1],k)) + f(n-1,s,k);
    return ans;
}
int main() {
    int n, k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    printf("%d", f(n,3,k));
    return 0;
}

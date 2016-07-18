#include <stdio.h>
#include <map>
using namespace std;
map<int, int> d[2001][4];
int a[2000];
int gcd(int b, int l) { return (l==0)?b:gcd(l,b%l); }
int f(int n, int s, int k) {
    if(d[n][s].count(k)>0) return d[n][s][k];
    if(s==0) {
        if(k==1) return d[n][s][k]=1; //f(n,3,k)에서 마지막에 들어온 k값을 최대공약수로 전부 없애는 경우만 1개로 카운트 할 수 있음. 왜냐면, 숫자 세개의 곱이 k로 나눠 떨어져야 하니까...
        else return d[n][s][k]=0;
    } else if(n==0) return d[n][s][k]=0;
    return d[n][s][k]=f(n-1,s,k)+f(n-1,s-1,k/gcd(a[n-1],k));
}
int main() {
    int n,k;
    scanf("%d%d", &n,&k);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    printf("%d", f(n,3,k));
    return 0;
}

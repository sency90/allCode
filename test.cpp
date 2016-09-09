#include <stdio.h>
#include <cstring>
using namespace std;
const long long T = 1e9;
long long d[1000001];
long long f(int x){
	if(x==1) return 0LL;
	else if(x==2) return 1LL;
    if(d[x] != -1LL) return d[x];
    return d[x] = (x-1)*(f(x-1)+f(x-2))%T; 
}
int main(){
	int n;
    memset(d, -1, sizeof(d));
    scanf("%d", &n);
    printf("%lld", f(n));
}
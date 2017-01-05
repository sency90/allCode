#include <cstdio>
using namespace std;

typedef long long ll;

ll d[101][101][101];

ll f(int n, int l, int r){
	
	if(l==1&&r==1) {
		if(n==1)return 1ll;
		else return 0ll;
	}
	else if(l<1||r<1||l+r>n+1) return 0ll;	

    if(d[n][l][r]) return d[n][l][r];
	return d[n][l][r] = ((n-2)*f(n-1,l,r)+f(n-1,l-1,r)+f(n-1,l,r-1))%1000000007;
}
int main(){
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	ll x=f(n,l,r);
	printf("%lld\n",x);

	return 0;
}


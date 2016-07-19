#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MOD 1000000007LL

typedef vector<vector<long long> > M;
int n, k;
M v, base;
M operator*(const M &l, const M &r){
	M ret(n, vector<long long> (n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				ret[i][j] = (ret[i][j] + l[i][k] * r[k][j])%MOD;
			}
		}
	}
	return ret;
}

M spow(const M &r, int m){
	M ret;
	ret.resize(n, vector<long long> (n));
	if(m==0) return base;
	if(m%2==1) return spow(r, m-1) * r;
	ret = spow(r, m/2);
	return ret * ret;
}
int main(){
	scanf("%d %d", &n, &k);
	v.resize(n, vector<long long> (n));
	base.resize(n, vector<long long> (n, 0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%lld", &v[i][j]);
		}
	}
	for(int i=0;i<n;i++) base[i][i] = 1LL;
	v = spow(v, k);
	long long ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans += v[i][j];
			if(ans > MOD) ans = ans % MOD;
		}
	}
	printf("%lld", ans);
}

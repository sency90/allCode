#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<pll> co;
ll lim = 2e16;
ll x0,y0,ax,ay,bx,by;
void mk(ll x, ll y) {
	if(x>lim || y>lim) return;
	co.emplace_back(x,y);
	mk(ax*x+bx, ay*y+by);
}
inline ll ABS(ll x) { return (x<0LL)?-x:x; }
int main() {
	scanf("%lld%lld%lld%lld%lld%lld",&x0,&y0,&ax,&ay,&bx,&by);
	mk(x0,y0);

	ll xs,ys,t;
	scanf("%lld%lld%lld",&xs,&ys,&t);

	vector<ll> sum(co.size(),0LL);
	vector<ll> dist(co.size(),0LL);
	for(int i=0; i<co.size(); i++) {
		ll x=co[i].first, y=co[i].second;
		dist[i] = ABS(xs-x) + ABS(ys-y);
		if(i!=0) sum[i] = sum[i-1]+(co[i].first-co[i-1].first)+(co[i].second-co[i-1].second);
	}

	ll mxans = 0LL;
	for(int i=0; i<co.size(); i++) {
		ll &mndist = dist[i];

		ll ans = 0LL;
		if(t>=mndist) {
			ans = 1;
			for(int j=i-1; j>=0; j--) {
				if(t>=mndist+(sum[i]-sum[j])) ans++;
			}
			for(int j=i+1; j<co.size(); j++) {
				if(t>=mndist+sum[i]+sum[j]) ans++;
			}
		}
		mxans = max(ans, mxans);
	}
	printf("%lld", mxans);
	return 0;
}

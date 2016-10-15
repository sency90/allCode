#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Rect {
	ll x1,y1,x2,y2;
	Rect() {}
	Rect(ll a,ll b,ll c,ll d) :x1(a),y1(b),x2(c),y2(d) {}
};
vector<Rect> rect;
int d[5000];
static inline bool cmp(const Rect &lhs,const Rect &rhs) {
	return lhs.x1<=rhs.x1&&lhs.x2>=rhs.x2&&lhs.y1<=rhs.y1&&lhs.y2>=rhs.y2;
}
static inline bool cmp2(const Rect &lhs,const Rect &rhs) {
	return (lhs.x2-lhs.x1)*(lhs.y2-lhs.y1)<(rhs.x2-rhs.x1)*(rhs.y2-rhs.y1);
}
static inline int f(int x) {
	if(x<0) return 0;
	int &ret = d[x];
	if(ret!=-1) return ret;
	else ret=0;
	for(int i=x-1; i>=0; i--) {
		if(cmp(rect[x],rect[i])) ret=max(ret,f(i)+1);
		//else ret=max(ret,f(i));
	}
	return ret;
}
template <typename T> static inline void fio(T *x) {
	register char c=0;
	while(c<33) c=getchar_unlocked();
	*x=0LL;
	while(c>33) {
		*x=*x*10LL+c-'0';
		c=getchar_unlocked();
	}
}
int main() {
	setbuf(stdout,NULL);
	freopen("input.txt","r",stdin);
	int tc; fio(&tc);
	for(int z=1; z<=tc; z++) {
		rect.clear();
		memset(d,-1,sizeof(d));
		int n,m,k; fio(&n);fio(&m);fio(&k);
		for(int i=0; i<k; i++) {
			ll x1,y1,x2,y2;
			fio(&x1); fio(&y1); fio(&x2); fio(&y2);
			rect.push_back(Rect(x1,y1,x2,y2));
		}
		sort(rect.begin(),rect.end(),cmp2);
		int mx=0;
		for(int i=1; i<k; i++) {
			mx=max(mx,f(i));
		}
		printf("Case #%d\n%d\n",z,mx+1);
	}
	return 0;
}

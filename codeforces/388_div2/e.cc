#include <cstdio>
#include <vector>
using namespace std;
int a[100001];
struct Fenwick{
    int s,e;
    vector<double> tree;
    Fenwick(int n):s(1),e(n),tree(n+1,0.0){}
    void init() {
        tree.clear();
        tree.resize(e+1,0.0);
    }
    void add(int at, double by) {
        for(int i=at; i<=e; i+=i&-i) tree[i]+=by;
    }
    double sum(int at) {
        double ret = 0.0;
        for(int i=at; i>=1; i-=i&-i) ret+=tree[i];
        return ret;
    }
};
int main(){
    int n,x;
	scanf("%d", &n);
    Fenwick fen(n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &x);
		a[x]=i;
	}

    double ans=0.0;
	for(int i=1; i<=n; i++) {
		ans += fen.sum(a[i])*(n-a[i]+1)/n/(n+1);
		fen.add(a[i],a[i]);
	}

    fen.init();
	for(int i=n; i>=1; i--) {
		ans -= fen.sum(a[i])*(n-a[i]+1)/n/(n+1);
		fen.add(a[i],a[i]);
	}

    fen.init();
	for(int i=n; i>=1; i--) {
		ans += fen.sum(a[i]);
		fen.add(a[i],1.0);
	}

	printf("%.10f",ans);
}

#include <stdio.h>
template <typename T>
class vector{
public:
	int sz,cur;
	T *v;
	vector():sz(1),cur(0){ v = new T; }
	inline void expand() {
		this->sz<<=1;
		T *tmp = new T[sz];
		for(int i=0; i<this->cur; i++) tmp[i] = this->v[i];
		delete(this->v);
		this->v = tmp;
	}
	inline void push_back(T x) {
		if(cur==sz) expand();
		v[cur++]=x;
	}
	inline T& operator[](int at) const { return v[at]; }
	vector& operator=(const vector &rhs) {
		this->v = new int(rhs.sz);
		for(int i=0; i<rhs.cur; i++) {
			this->v[i] = rhs.v[i];
		}
		this->sz = rhs.sz;
		this->cur = rhs.cur;
		return *this;
	}
	inline int size() { return cur; }
};
vector<int> v[1000001];
bool chk[1000001];
int cnt=0;
void dfs(int x,int r) {
	bool haveToChk = false;
	for(int i=0; i<v[x].size(); i++) {
		if(v[x][i]^r) {
			dfs(v[x][i],x);
			haveToChk|=!chk[v[x][i]];
		}
	}
	if(haveToChk) chk[x]=true,cnt++;
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	printf("%d",cnt);
	return 0;
}

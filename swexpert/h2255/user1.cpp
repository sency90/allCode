#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;
struct Edge{
	int x,c;
	Edge() {}
	Edge(int x, int c):x(x),c(c) {}
	bool operator<(const Edge & rhs) const {
		return c>rhs.c;
	}
};
template <typename T>
struct Vector{
	T *arr;
	int sz, idx;
	Vector():arr(NULL),sz(4),idx(0) {
		arr = (T*)malloc(4*sizeof(T));
	}
	virtual ~Vector() {
		if(arr) { free(arr); arr=NULL; }
	}

	void push_back(const T & x) {
		if(idx == sz) {
			expand(sz*2);
		}
		arr[idx++] = x;
	}

	void clear() { idx=0; }
	int size() const { return idx; }
	void expand(int esz) {
		if(sz < esz) {
			T *tmp = realloc(arr, esz*sizeof(T));
			if(tmp) arr = tmp;
		}
	}
	void resize(int n, const T & t) {
		expand(n);
		for(int i=0; i<n; i++) arr[i] = t;
	}

};
Vector<Vector<Edge>> v, rv;
//vector<vector<Edge>> v,rv;
priority_queue<Edge> mnh;
int en[600], en_i;
int find_v(int x) {
	for(int i=0; i<en_i; i++) {
		if(x == en[i]) return i;
	}
	return -1; //not found
}
int init(int N, int sCity[], int eCity[], int mCost[]) {
	en_i=0;
	v.clear(); rv.clear();
	v.resize(600, vector<Edge>());
	rv.resize(600, vector<Edge>());
	for(int i=0; i<N; i++) {
		int s = find_v(sCity[i]);
		int e = find_v(eCity[i]);
		if(s<0) {
			s = en_i;
			en[en_i++] = sCity[i];
		}
		if(e<0) {
			e = en_i;
			en[en_i++] = eCity[i];
		}
		v[s].emplace_back(e, mCost[i]);
		rv[e].emplace_back(s, mCost[i]);
	}
	return en_i;
}

void add(int sCity, int eCity, int mCost) {
	int s = find_v(sCity);
	int e = find_v(eCity);
	v[s].emplace_back(e, mCost);
	rv[e].emplace_back(s, mCost);
	return;
}

int dist[601];
int cost(int mHub) {
	int m = find_v(mHub);
	int N = en_i;
	vector<bool> chk(N, false);
	memset(dist, 0x3f, N*sizeof(int));
	mnh.emplace(m,0);
	dist[m]=0;
	Edge ed;
	for(int i=0; i<N; i++) {
		while(!mnh.empty()) {
			ed = mnh.top(); mnh.pop();
			if(!chk[ed.x]) break;
		}
		chk[ed.x] = true;
		for(int i=0; i<v[ed.x].size(); i++) {
			int y = v[ed.x][i].x;
			int tc = ed.c + v[ed.x][i].c;

			if(dist[y] > tc) {
				dist[y] = tc;
				mnh.emplace(y, tc);
			}
		}
	}
	{ priority_queue<Edge> empty; swap(mnh, empty); }
	int ret = 0;
	for(int i=0; i<N; i++) ret += dist[i];

	chk.clear(); chk.resize(N, false);
	memset(dist, 0x3f, N*sizeof(int));
	mnh.emplace(m,0);
	dist[m]=0;
	for(int i=0; i<N; i++) {
		while(!mnh.empty()) {
			ed = mnh.top(); mnh.pop();
			if(!chk[ed.x]) break;
		}
		chk[ed.x] = true;
		for(int i=0; i<rv[ed.x].size(); i++) {
			int y = rv[ed.x][i].x;
			int tc = ed.c + rv[ed.x][i].c;

			if(dist[y] > tc) {
				dist[y] = tc;
				mnh.emplace(y, tc);
			}
		}
	}
	{ priority_queue<Edge> empty; swap(mnh, empty); }
	for(int i=0; i<N; i++) ret += dist[i];
	return ret;



}

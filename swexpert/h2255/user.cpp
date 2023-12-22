#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
struct Edge{
	int x,c;
	Edge() {}
	Edge(int x, int c):x(x),c(c) {}
	bool operator<(const Edge & rhs) const {
		return c>rhs.c;
	}
};
unordered_map<int, int> hmap;
vector<vector<Edge>> v,rv;
priority_queue<Edge> mnh;
int init(int N, int sCity[], int eCity[], int mCost[]) {
	int cnt = 0;
	hmap.clear();
	for(int i=0; i<N; i++) {
		if(hmap.count(sCity[i])==0) hmap[sCity[i]] = cnt++;
		if(hmap.count(eCity[i])==0) hmap[eCity[i]] = cnt++;
	}
	v.clear(); rv.clear();
	v.resize(cnt, vector<Edge>());
	rv.resize(cnt, vector<Edge>());
	for(int i=0; i<N; i++) {
		int s = hmap[sCity[i]];
		int e = hmap[eCity[i]];
		v[s].emplace_back(e, mCost[i]);
		rv[e].emplace_back(s, mCost[i]);
	}
	return cnt;
}

void add(int sCity, int eCity, int mCost) {
	int s = hmap[sCity];
	int e = hmap[eCity];
	v[s].emplace_back(e, mCost);
	rv[e].emplace_back(s, mCost);
	return;
}

int dist[601];
int cost(int mHub) {
	int m = hmap[mHub];
	int N = hmap.size();
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

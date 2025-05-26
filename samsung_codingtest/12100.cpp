#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> v[2],w[5];
int GetMax(vector<vector<int>> &v) {
	int mx = 0;
	for(int i=0; i<(int)v.size(); i++) {
		for(int j=0; j<(int)v[i].size(); j++) {
			mx = max(mx, v[i][j]);
		}
	}
	return mx;
}

int n;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<int> level;
vector<vector<int>> tmp;

void Rotate90(vector<vector<int>> *v, int &t) {
	//v[t^1].clear();
	for(int j=0,p=0; j<n; j++,p++) {
		for(int i=n-1,q=0; i>=0; i--,q++) {
			v[t^1][p][q] = v[t][i][j];
		}
	}
	t^=1;
}

void Move(vector<vector<int>> *v, int &t, int dir) {
	for(int i=0; i<dir; i++) {
		Rotate90(v, t);
	}

	tmp.clear();
	tmp.resize(n, vector<int>(n, 0));

	//compress
	level.clear();
	level.resize(n, 0);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(v[t][i][j]>0) {
				tmp[level[j]++][j] = v[t][i][j];
				v[t][i][j]=0;
			}
		}
	}

	//merge
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(tmp[i][j]) {
				if(i+1<n) {
					if(tmp[i+1][j]>0 && tmp[i][j]==tmp[i+1][j]) {
						tmp[i][j]*=2;
						tmp[i+1][j]=0;
					}
				}
			}
		}
	}

	//compress
	v[t].clear();
	v[t].resize(n, vector<int>(n, 0));
	level.clear();
	level.resize(n, 0);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(tmp[i][j]>0) {
				v[t][level[j]++][j] = tmp[i][j];
			}
		}
	}

	if(dir==0) return;
	for(int i=dir; i<4; i++) {
		Rotate90(v, t);
	}
}
int mx,t;
void Dfs(int x) {
	if(x<=0) {
		mx = max(mx, GetMax(v[t]));
		return;
	}
	for(int i=0; i<4; i++) {
		w[x-1] = v[t];
		Move(v,t,i);
		Dfs(x-1);
		v[t] = w[x-1];
	}
}
int main() {
	scanf("%d", &n);
	v[t].resize(n, vector<int>(n));
	v[t^1].resize(n, vector<int>(n));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d", &v[t][i][j]);
		}
	}

	Dfs(5);
	printf("%d\n", mx);

	return 0;
}

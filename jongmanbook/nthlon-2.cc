#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int v[402][402];
int dij(int s){
	vector<int> dist(402, 0x3f3f3f3f);
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	while(!q.empty()){
		int cost = -q.top().first;
		int here = q.top().second;
		q.pop();
		if(dist[here] < cost) continue;
		for(int i=1;i<402;i++){
			int ncost = cost + v[here][i];
			if(ncost < dist[i]){
				dist[i] = ncost;
				q.push(make_pair(-ncost, i));
			}
		}
	}
	return dist[s];
}

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		memset(v, 0x3f, sizeof(v));
		int n;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			int s, e;
			scanf("%d %d", &s, &e);
			for(int j=0;j<402;j++){
				int next = (j?j:201) + (s-e);
				if(next < 1 || next > 401) continue;
				v[j][next] = min(v[j][next], s);
			}
            puts("");
		}
		int result = dij(201);
		if(result == 0x3f3f3f3f) printf("IMPOSSIBLE\n");
		else printf("%d\n", result);
	}
}

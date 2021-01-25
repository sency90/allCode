#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
using pii = pair<int,int>;
priority_queue<pii, vector<pii>, greater<pii>> mnh;
int v[1000001], ans[1000001];

int main() {
	memset(ans,-1,sizeof(ans));
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int x; scanf("%d", &x);
		while(!mnh.empty()) {
			pii info = mnh.top();
			if(info.first < x) {
				ans[info.second] = x;
				mnh.pop();
			}
			else break;
		}
		mnh.emplace(x,i);
	}

	for(int i=0; i<n; i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}

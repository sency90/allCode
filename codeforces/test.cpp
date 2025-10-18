#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
priority_queue<int, vector<int>, greater<int>> mnh;
int main() {
	int v[6]= {3,6,1,2,5,4};
	for(int i=0; i<6; i++) {
		mnh.push(v[i]);
	}
	while(!mnh.empty()) {
		printf("%d\n", mnh.top());
		mnh.pop();
	}
	return 0;
}

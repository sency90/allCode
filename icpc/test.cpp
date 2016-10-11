#include <cstdio>
using namespace std;
int v[10001];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d",&v[i]);
	}
	for(int i=0; i<n; i++) {
		printf("%d\n", v[i]);
	}
	return 0;
}
#include <cstdio>
int n, pre[1000], post[1000], postInv[1001];

void travel(int preSt, int postSt, int cnt) {
	if(cnt==0) return;
	else if(cnt==1) {
		printf("%d ", pre[preSt]);
		return;
	}

	int newCnt = postInv[pre[preSt+1]]-postSt+1;
	travel(preSt+1, postSt, newCnt);
	printf("%d ", pre[preSt]);
	travel(preSt+newCnt+1, postSt+newCnt, cnt-newCnt-1);
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&pre[i]);
	for(int i=0;i<n;i++) {
		scanf("%d",&post[i]);
		postInv[post[i]] = i;
	}
	travel(0, 0, n);
	return 0;
}

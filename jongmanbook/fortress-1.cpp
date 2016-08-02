#include <stdio.h>
#include <algorithm>
using namespace std;
int c,n,ans;
struct st {
	int x, y, r;
	bool operator <(const st& a) const{
		return r < a.r;
	}
}fortress[100];
int buf[100];
int main() {
	scanf("%d", &c);
	while (c--) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d %d %d", &fortress[i].x, &fortress[i].y, &fortress[i].r);
		sort(fortress, fortress + n);
		for (int i = 0; i < n-1; i++)
			for (int j = i + 1; j < n; j++) {
				int dx = (fortress[i].x - fortress[j].x);
				int dy = (fortress[i].y - fortress[j].y);
				if (dx*dx + dy*dy < fortress[j].r*fortress[j].r) {
                    printf("buf[%d]:%d, buf[%d]:%d\n",i,buf[i],j,buf[j]);
					ans = max(ans, buf[j] + buf[i]+1);
                    printf("ans:%d, buf[%d]+buf[%d]+1: %d\n",ans, j,i,buf[j]+buf[i]+1);
					buf[j] = max(buf[j], buf[i] + 1);
					break;
				}
			}
		printf("%d\n", ans);
		for (int i = 0; i < n; i++)buf[i] = 0;
	}
}

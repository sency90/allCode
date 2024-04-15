#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int> dic;
unordered_map<int, int> udic;
int a[101];
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int k,q; scanf("%d%d",&k,&q);
		for(int i=0; i<k; i++) {
			scanf("%d", &a[i]);
		}
		for(int i=0; i<q; i++) {
			int n; scanf("%d", &n);
			for(int j=1; j<=n; j++) {
				dic[j]=0;
			}
			int cnt=0;
			do {
				int u=0,v=0;
				udic.clear();
				cnt++;
				for(auto it : dic) {
					u++;
					if(u == a[v]) {
						v++;
						udic[it.first]=0;
					}
					else if(u > a[v]) break;
					if(v==k) break;
				} 
				for(auto it : udic) {
					dic.erase(it.first);
				}
				printf("t: ");
				for(auto it : dic) printf("%d ", it.first);
				puts("");

				if(dic.size() <= a[0]) break;
			} while(!udic.empty());
			printf("%d ", cnt);
			dic.clear();
			udic.clear();
		}
		puts("");
	}
	return 0;
}

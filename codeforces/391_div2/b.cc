#include <cstdio>
#include <algorithm>
using namespace std;
int cnt[100001];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
    int mx=1;
    for(int i=2LL; i<=100000; i++) {
        int cur=0;
        for(int j=i; j<=100000; j+=i) cur += cnt[j];
        mx=max(mx,cur);
    }
    printf("%d", mx);
    return 0;
}

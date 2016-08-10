#include <cstdio>
using namespace std;
int cnt[100001], p[100001], pp[100001];
int main() {
    int n,d, ans=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        cnt[d]++;
        if(cnt[d]>1) {
            ans+=(n-i);
            printf("ans: %d\n", ans);
            ans+=p[d]-1;
            printf("ans: %d, p[d]-1: %d\n", ans,p[d]-1);
            ans-=cnt[d]-2;
            printf("ans: %d, cnt[d]-2: %d\n", ans,cnt[d]-2);
            puts("--------------------------");
        }
        pp[d]=p[d];
        p[d]=i+1;
    }
    printf("%d", n*(n+1)/2-ans);
    return 0;
}

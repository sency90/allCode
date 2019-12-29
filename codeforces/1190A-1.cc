#include <cstdio>
#include <cstring>
typedef long long ll;
using namespace std;
ll p[100001];
int main() {
    ll n,m,k; scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=0; i<m; i++) {
        scanf("%lld", &p[i]);
        p[i]--;
    }

    ll curPage=p[0]/k, rmCnt=0;
    int i=0, ans=0;
    while(rmCnt < m) {
        curPage=(p[i]-rmCnt)/k;
        while(curPage == (p[i]-rmCnt)/k) i++;
        rmCnt=i;
        ans++;
    }
    printf("%d", ans);
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <cstring>
const int M=35000;
using namespace std;
typedef pair<int,int> pii;
int cnt[M], idx[100001], ans[100001];
pii v[100001];
int main() {
    int n,c; scanf("%d%d",&n,&c);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        v[i].first=x/M; v[i].second=x%M;
    }

    for(int i=0; i<n; i++) cnt[v[i].second]++;
    for(int i=1; i<M; i++) cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--) idx[--cnt[v[i].second]]=i;

    memset(cnt,0,sizeof(cnt));
    for(int i=0; i<n; i++) cnt[v[i].first]++;
    for(int i=1; i<M; i++) cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--) ans[--cnt[v[idx[i]].first]]=idx[i];


    if(!c) for(int i=0; i<n; i++) printf("%d\n", v[ans[i]].first*M + v[ans[i]].second);
    else for(int i=n-1; i>=0; i--) printf("%d\n", v[ans[i]].first*M + v[ans[i]].second);
    return 0;
}

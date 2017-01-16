#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int cnt[13];
int main() {
    int n,x; scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        v.push_back(x);
    }
    int t; scanf("%d", &t);
    t<<=1;
    sort(v.begin(), v.end());
    int lim = (1<<n);
    int sum=0;
    for(int i=0; i<lim; i++) {
        int bit=i;
        memset(cnt,0,sizeof(cnt));
        for(int j=0; j<n; j++, bit>>=1) {
            if(bit&1) cnt[j+1]=cnt[j]+1;
            else {
                cnt[j+1]=cnt[j];
                auto it = lower_bound(v.begin(), v.end(), v[j]-t);
                int idx = it-v.begin();
                sum+=cnt[j]-cnt[idx];
            }
        }
    }
    printf("%lf", (double)sum/lim);
    return 0;
}

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> idx;
int cnt[31];
int square[31];
int main() {
    int n,q,x;
    scanf("%d%d",&n,&q);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        for(int j=0; j<=30; j++, x>>=1) {
            if(x==1) {
                if(cnt[j]++ == 0) {
                    idx.push_back(j);
                    break;
                }
            }
        }
    }

    sort(idx.begin(), idx.end(), [](const int lhs, const int rhs){return lhs>rhs;});
    for(int i=0; i<=30; i++) square[i] = (1<<i);
    for(int i=0; i<q; i++) {
        scanf("%d", &x);

        int ans=0;
        for(int j=0; j<idx.size(); j++) {
            int val = square[idx[j]];
            int tmp = x/val;
            //printf("val:%d x/val:%d\n", val, tmp);
            if(tmp==0) continue;
            else if(tmp >= cnt[idx[j]]) {
                x-=val*cnt[idx[j]];
                ans+=cnt[idx[j]];
            } else {
                x-=val*tmp;
                ans+=tmp;
            }
        }
        if(x==0) printf("%d\n", ans);
        else puts("-1");
    }
    return 0;
}

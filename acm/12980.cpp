#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
bool chk[101];
int d[101];
vector<int> v, emptyIdx;
int main() {
    int n, s;
    scanf("%d%d",&n,&s);
    for(int i=1; i<=n; i++) {
        scanf("%d", &d[i]);
        if(d[i]!=0) chk[d[i]] = true;
        else emptyIdx.push_back(i);
    }
    for(int i=1; i<=n; i++) {
        if(!chk[i]) v.push_back(i);
    }
    int ps, ans=0;
    sort(v.begin(), v.end());
    do{
        for(int i=0; i<emptyIdx.size(); i++) {
            d[emptyIdx[i]]=v[i];
        }
        ps=0;
        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
                if(d[i]<d[j]) ps++;
                if(ps>s) break;
            }
            if(ps>s) break;
        }
        if(ps==s) ans++;
    }while(next_permutation(v.begin(), v.end()));
    printf("%d", ans);
    return 0;
}

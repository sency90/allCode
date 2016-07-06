#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int d[100001];
int main() {
    int n, k;
    scanf("%d%d",&n,&k);
    vector<pair<int,int> > v(n);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&v[i].first, &v[i].second);
    }
    for(int i=0; i<n; i++) {
        for(int j=k; j-v[i].first >= 0; j--) {
            d[j] = max(d[j], d[j-v[i].first]+v[i].second);
        }
        /*
        for(int j=0; j<=k; j++) {
            if(j+v[i].first > k) continue;
            d[j+v[i].first] = max(d[j + v[i].first], d[j] + v[i].second);
        }
        */
    }
    printf("%d", d[k]);
    return 0;
}

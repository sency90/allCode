#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
vector<pair<int,int> > mons;
int sade[100002];
int main() {
    int m, n, l, x, y;
    scanf("%d %d %d", &m, &n, &l);
    for(int i=0; i<m; i++) {
        scanf("%d", &sade[i]);
    }
    for(int i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        mons.push_back(make_pair(x,y));
    }
    sort(sade, sade+m);
    sort(mons.begin(), mons.end());
    sade[m] = mons[n-1].first+1;

    int midx = 0, cnt=0;
    for(int i=0; i<m; i++) {
        while(midx < n) {
            if(mons[midx].first <= sade[i]) {
                if(abs(mons[midx].first-sade[i]) + mons[midx].second <= l) {
                    cnt++;
                    mons[midx].second = l+1;
                }
                midx++;
            } else break;
        }
        for(int j=midx; j<n; j++) {
            if(mons[j].first < sade[i+1]) {
                if(abs(mons[j].first-sade[i]) + mons[j].second <= l) {
                    cnt++;
                    mons[j].second = l+1;
                }
            } else break;
        }
    }
    printf("%d", cnt);
    return 0;
}

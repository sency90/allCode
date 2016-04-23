#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> uxlist, dxlist;
bool cmp(const int &rhs, const int &lhs) {
    return rhs > lhs;
}
int dv[30001], uv[30001];
int main() {
    int n, k, s, x, y;
    int dsum=0, usum=0;
    scanf("%d %d %d", &n, &k, &s);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        if(x < s) {
            dv[s-x] = y;
            dxlist.push_back(s-x);
            dsum += y;
        } else {
            uv[x-s] = y;
            uxlist.push_back(x-s);
            usum += y;
        }
    }
    sort(dxlist.begin(), dxlist.end(), cmp);
    sort(uxlist.begin(), uxlist.end(), cmp);
    /*
    for(int i=0; i<dxlist.size(); i++) printf("%d\n", dxlist[i]);
    return 0;
    */

    int ps=0, pi=0, ans=0, pans=0;
    while(dsum > 0) {
        for(int i=pi; i<dxlist.size(); i++) {
            if(dv[dxlist[i]]) {
                printf("ps: %d\n", ps);
                printf("dv[dxlist[i]]: %d\n", dv[dxlist[i]]);
                if(ps+dv[dxlist[i]] > k) {
                    ps=k;
                    dv[dxlist[i]] = ps+dv[dxlist[i]]-k;
                    pans=dxlist[i];
                    pi=i;
                    break;
                } else {
                ps += dv[dxlist[i]];
                dv[dxlist[i]] = 0;
                pans=dxlist[i];
                pi=i;
                }
            }
        }
        printf("test: %d\n", pans);
        ans += pans;
        pans=0;
        dsum-=ps;
        printf("dsum: %d\n", dsum);
        ps=0;
    }
    ps = 0, pi=0;
    while(usum > 0) {
        for(int i=pi; i<uxlist.size(); i++) {
            if(uv[uxlist[i]]) {
                if(ps+uv[uxlist[i]] > k) {
                    ps=k;
                    uv[uxlist[i]] = ps+uv[uxlist[i]]-k;
                    pans=uxlist[i];
                    pi=i;
                    break;
                }
                ps += uv[uxlist[i]];
                uv[uxlist[i]] = 0;
                pans=uxlist[i];
                pi=i;
            }
        }
        ans += pans;
        pans = 0;
        usum -= ps;
        ps = 0;
    }
    printf("%d", ans*2);
    return 0;
}

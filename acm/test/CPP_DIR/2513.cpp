#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> list;
int v[30001];
bool cmp(const int &rhs, const int &lhs) {
    return rhs > lhs;
}
int main() {
    int n, k, s, x, y, ps=0, ans=0, ds=0, us=0, pans=0, pi=0;
    scanf("%d %d %d", &n, &k, &s);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        v[x] = y;
        list.push_back(x);
        if(s-x>0) ds += y;
        else us += y;
    }
    sort(list.begin(), list.end());
    while(ds > 0) {
        for(int i=pi; i<=list.size(); i++) {
            if(list[i] >= s) break;
            if(v[list[i]] == 0 ) continue;
            if(v[list[i]]+ps <= k) {
                pi=i;
                ps += v[list[i]];
                v[list[i]]=0;
                pans = s-list[i];
            } else {
                pi=i;
                ps = k;
                v[list[i]] = v[list[i]] + ps - k;
                pans = s-list[i];
                break;
            }
            printf("%d\n", ps);
        }
        ans += pans; pans=0;
        ds -= ps; ps = 0;
    }
    pi=0;
    sort(list.begin(), list.end(), cmp);
    while(us > 0) {
        for(int i=pi; i<=list.size(); i++) {
            if(list[i] < s) break;
            if(v[list[i]]+ps <= k) {
                pi=i;
                ps += v[list[i]];
                v[list[i]]=0;
                pans = list[i]-s;
            } else {
                pi=i;
                ps = k;
                v[list[i]] = v[list[i]] + ps - k;
                pans = list[i]-s;
                break;
            }
        }
        ans+=pans; pans=0;
        us -= ps; ps = 0;
    }
    printf("%d", ans*2);
    return 0;
}

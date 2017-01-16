#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
map<double, vector<int>> mp;
double a[2];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        double x1,y1,x2,y2;
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        double mx = max(y1/x1,y2/x2);
        double mn = min(y1/x1,y2/x2);
        mp[mn].push_back(1);
        mp[mx].push_back(-1);
    }
    int cnt=0, mx=0;
    for(auto &p: mp) {
        int plus=0, minus=0;
        for(int q: p.second) {
            if(q>0) plus++;
            else minus--;
        }
        if(plus&&minus) {
            cnt+=plus;
            mx=max(mx,cnt);
            cnt+=minus;
        } else {
            cnt+=plus+minus;
            mx=max(mx,cnt);
        }
    }
    printf("%d\n", mx);
    return 0;
}

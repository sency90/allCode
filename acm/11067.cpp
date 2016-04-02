#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
bool cmp(const pi &lhs, const pi &rhs) {
    if(lhs.first == rhs.first) return lhs.second < rhs.second;
    else return lhs.first < rhs.first;
}
int main() {
    int t,n,m,x,y;
    scanf("%d", &t);
    while(t--) {
        vector<pi> v, order;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d %d", &x, &y);
            v.push_back(make_pair(x,y));
        }
        sort(v.begin(), v.end(), cmp);
        int px=-1, py=0, sidx=0, i, yy=0, ry=0;
        bool haveToReverse=false;
        for(i=0; i<v.size(); i++) {
            x=v[i].first;
            y=v[i].second;
            if(x > px) {
                if(py > y) {
                    sidx=i;
                    yy = py;
                    ry = y;
                    haveToReverse = true;
                } else order.push_back(v[i]);
            } else {
                if(haveToReverse && y==yy) {
                    haveToReverse = false;
                    for(int j=i; j>=sidx; j--) {
                        order.push_back(v[j]);
                    }
                    y=ry;
                } else if(!haveToReverse) order.push_back(v[i]);
            }
            px = x;
            py = y;
        }
        if(haveToReverse) {
            for(int j=i; j>=sidx; j--) {
                order.push_back(v[j]);
            }
        }
        scanf("%d", &m);
        for(int i=0; i<m; i++) {
            scanf("%d", &sidx);
            printf("%d %d\n", order[sidx-1].first, order[sidx-1].second);
        }
    }
    return 0;
}

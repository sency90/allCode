#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
struct Info{
    int d, idx;
    Info(int dd, int iidx) {
        d=dd; idx=iidx;
    }
    //for sorting
    bool operator<(const Info& rhs) const{
        if(d==rhs.d) return idx < rhs.idx;
        else return d < rhs.d;
    }
    //for minheap
    bool operator>(const Info& rhs) const {
        return d > rhs.d;
    }
};
vector<Info> v;
priority_queue<Info, vector<Info>, greater<Info> > mnh;
int main() {
    int n, d;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &d);
        v.push_back(Info(d,i));
    }
    sort(v.begin(), v.end());
    mnh.push(Info(v[0].idx, v[0].idx));
    int pLevel=0, pd=v[0].d, k=1, pk=0, j=0;
    for(int i=1; i<v.size(); i++) {
        if(pd != v[i].d) {
            pd = v[i].d;
            while(v[i].d > i) {
                pLevel += n-pk;

                printf("[%d] pLevel: %d, pk:%d\n", i, pLevel, pk);
                //pk += k;
                pk = mnh.size();
                k=1;
                v[i].d--;
            }
            mnh.push(Info(v[i].idx, pLevel + k));
        } else mnh.push(Info(v[i].idx, pLevel + (++k)));
    }
    while(!mnh.empty()) {
        printf("%d\n", mnh.top().idx);
        mnh.pop();
    }
    return 0;
}

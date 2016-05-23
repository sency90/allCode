//좌표를 받아서 둘로 저장한다.
//둘다 x를 오름차순으로 정렬하는데,
//하나는 y를 오름차순으로, 다른 하나는 내림차순으로 저장한다.
//x값이 달라질 때, 이전 y값과 현재 y값을 비교해서 다르면
//y내림차순을 출력하도록 하고, 같은 경우 y오름차순 좌표를 출력하도록 한다.
//
//실수 - vector를 계속 재사용해야돼서 초기화 해줘야 함.
//실수 - as, ds를 선택하는 부분에서 거꾸로 썼음 ㅡ,.ㅡ;;
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > as, ds, ans;
int main() {
    int t, n, x, y;
    scanf("%d", &t);
    while(t--) {
        as.clear();
        ds.clear();
        ans.clear();
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d%d",&x,&y);
            as.push_back(make_pair(x, y));
            ds.push_back(make_pair(x, -y));
        }
        sort(as.begin(), as.end());
        sort(ds.begin(), ds.end());
        pair<int, int> pco;
        bool isAs;
        if(ds[0].second != 0) {
            ans.push_back(as[0]);
            pco = ans[0];
            isAs = true;
        } else {
            ans.push_back(make_pair(ds[0].first, -ds[0].second));
            pco = ans[0];
            isAs = false;
        }
        for(int i=1; i<as.size(); i++) {
            if(pco.first != as[i].first) {
                if(pco.second == as[i].second) {
                    ans.push_back(as[i]);
                    pco = ans[i];
                    isAs = true;
                } else {
                    ans.push_back(make_pair(ds[i].first, -ds[i].second));
                    pco = ans[i];
                    isAs = false;
                }
            } else {
                if(isAs) {
                    ans.push_back(as[i]);
                    pco = ans[i];
                } else {
                    ans.push_back(make_pair(ds[i].first, -ds[i].second));
                    pco = ans[i];
                }
            }
        }
        int m, d; scanf("%d", &m);
        for(int i=0; i<m; i++) {
            scanf("%d", &d);
            printf("%d %d\n", ans[d-1].first, ans[d-1].second);
        }
    }
    return 0;
}

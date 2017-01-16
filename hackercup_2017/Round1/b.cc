#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<pii> co,cox,coy,bco,board;
int getcnt(int sx, int sy, int ex, int ey) {
    if(ex<sx||ey<sy) return 0;

    int cnt=0;
    auto s = lower_bound(cox.begin(), cox.end(), pii(sx,0));
    auto e = lower_bound(cox.begin(), cox.end(), pii(ex+1,0));
    for(auto it=s; it!=e; it++) {
        int y=co[it->second].second;
        if(sy<=y && y<=ey) cnt++;
    }
    return cnt;
}
int main() {
    freopen("b_input.txt", "r", stdin);
    freopen("b_output.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    for(int z=1; z<=tc; z++) {
        co.clear();
        cox.clear();
        coy.clear();
        board.clear();
        bco.clear();

        int n,r;
        scanf("%d%d",&n,&r);
        for(int i=0; i<n; i++) {
            int x,y; scanf("%d%d",&x,&y);
            co.push_back({x,y});
            cox.push_back({x,i});
            coy.push_back({y,i});
        }
        sort(cox.begin(), cox.end());
        int idx=0, mx=0;
        for(auto &cx: cox) {
            for(auto &cy: coy) {
                int bx=cx.first, by=cy.first;
                int cnt=getcnt(bx,by,bx+r,by+r);
                mx = max(mx,cnt);
                board.push_back({cnt,idx++});
                bco.push_back({bx,by});
            }
        }
        for(int i=0; i<board.size(); i++) {
            int bxi=bco[board[i].second].first, byi=bco[board[i].second].second;
            for(int j=0; j<board.size(); j++) {
                if(i==j) continue;
                int bxj=bco[board[j].second].first, byj=bco[board[j].second].second;
                mx = max(mx,board[i].first+board[j].first-getcnt(bxj,byj,bxi+r,byi+r));
            }
        }
        printf("Case #%d: %d\n",z,mx);
    }
    return 0;
}

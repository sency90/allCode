#include <bits/stdc++.h>
using namespace std;
vector<int> sw[10] = {
    {0,1,2},
    {3,7,9,11},
    {4,10,14,15},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15},
    {3,14,15},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}
};
int ck[16];
int mn_ans;
const int INF = 0x3f3f3f3f;

inline void Rotate(int x, int n) {
    ck[x]+=3*n;
    if(ck[x]>12) ck[x]-=12;
}

inline void RevRotate(int x, int n) {
    ck[x]-=3*n;
    if(ck[x]<=0) ck[x]+=12;
}

void Dfs(int x, int ans) {
    if(x==10) {
        int cnt=0;
        for(int i=0; i<16; i++) {
            if(ck[i]==12) cnt++;
        }
        if(cnt==16) mn_ans = min(mn_ans, ans);
        return;
    }

    for(int i = 0; i < 4; i++) {
        if(i > 0) {
            for(int ck_no : sw[x]) {
                Rotate(ck_no, i);
            }
        }
        Dfs(x+1,ans+i);
        if(i > 0) {
            for(int ck_no : sw[x]) {
                RevRotate(ck_no, i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        mn_ans = INF;
        for(int i=0; i<16; i++) cin >> ck[i];
        Dfs(0,0);
        if(mn_ans == INF) puts("-1");
        else printf("%d\n", mn_ans);
    }
    return 0;
}
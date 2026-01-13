#include <bits/stdc++.h>
using namespace std;
const int NA = -1;
const int INF = 0x3f3f3f3f;
int n, m;
string p[51];
unordered_map<string, int> pno_by_p;
vector<vector<int>> pno_set_by_fno;
int pno_chk[51];
int ans;
inline void Init(int n, int m) {
    pno_by_p.clear();
    pno_set_by_fno.clear();
    pno_set_by_fno.resize(m);
    memset(pno_chk, 0, sizeof(pno_chk));
    ans = INF;
}
void Dfs(int fno, int food_cnt, int person_cnt) {
    if(food_cnt >= ans) return;
    if(person_cnt == n) {
        ans = min(ans, food_cnt);
        return;
    }
    if(fno==m) return;

    int pcnt=0;
    for(int i=0; i<pno_set_by_fno[fno].size(); i++) {
        int pno = pno_set_by_fno[fno][i];
        if (!pno_chk[pno]) pcnt++;
        pno_chk[pno]++;
    }
    Dfs(fno+1, food_cnt+1, person_cnt+pcnt); //fno를 먹은 경우
    for(int i=0; i<pno_set_by_fno[fno].size(); i++) {
        int pno = pno_set_by_fno[fno][i];
        pno_chk[pno]--;
    }
    Dfs(fno+1, food_cnt, person_cnt); //fno를 안먹은 경우
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m;
        Init(n, m);
        for(int pno=0; pno<n; pno++) {
            cin >> p[pno];
            pno_by_p[p[pno]] = pno;
        }
        string person;
        for(int fno=0; fno<m; fno++) {
            int cnt; cin >> cnt;
            for (int z = 0; z < cnt; z++) {
                cin >> person;
                pno_set_by_fno[fno].push_back(pno_by_p[person]);
            }
        }

        Dfs(0,0,0);
        printf("%d\n", ans);
    }
    return 0;
}
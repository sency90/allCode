#include <bits/stdc++.h>
using namespace std;
const int NA = -1;
const int INF = 0x3f3f3f3f;
int n, m;
string p[51];
unordered_map<string, int> pno_by_p;
vector<vector<int>> pno_list_by_fno;
int pno_chk[51];
int ans;
vector<vector<int>> fno_list_by_pno;
bool fno_chk[51];

inline void Init(int n, int m) {
    pno_by_p.clear();

    pno_list_by_fno.clear(); pno_list_by_fno.resize(m);

    memset(pno_chk, 0, sizeof(pno_chk));
    ans = INF;

    fno_list_by_pno.clear(); fno_list_by_pno.resize(n);

    memset(fno_chk, false, sizeof(fno_chk));
}

void Dfs(int fno, int food_cnt, int person_cnt) {
    if(food_cnt >= ans) return;
    if(person_cnt == n) {
        ans = min(ans, food_cnt);
        return;
    }
    if(fno<0) return;
    //if(fno==m) return;

    fno_chk[fno] = true;

    //일단 fno를 요리한다.
    int pcnt=0;
    for (int s_pno : pno_list_by_fno[fno]) {
        if (!pno_chk[s_pno]) pcnt++;
        pno_chk[s_pno]++;
    }

    //음식을 아직 아무것도 먹지 않은 사람들 중 하나를 택해서,
    //그 사람이 먹지 않은 음식들 중 하나를 고르는데,
    //그 음식을 먹을 수 있는 사람들이 가장 많은 음식으로 고른다.
    int mx=-1, nfno=-1;
    for(int pno=0; pno<n; pno++) {
        if(pno_chk[pno]) continue;
        for(int nxt_fno : fno_list_by_pno[pno]) {
            if(fno_chk[nxt_fno]) continue;
            //이미 탐색한 음식인지만 체크하면 됨.
            if(mx < (int)pno_list_by_fno[nxt_fno].size()) {
                mx = (int)pno_list_by_fno[nxt_fno].size();
                nfno = nxt_fno;
            }
        }
    }
    Dfs(nfno, food_cnt + 1, person_cnt + pcnt);

    for (int s_pno : pno_list_by_fno[fno]) {
        pno_chk[s_pno]--;
    }
    Dfs(nfno, food_cnt, person_cnt);
    fno_chk[fno] = false;
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
                pno_list_by_fno[fno].push_back(pno_by_p[person]);
                fno_list_by_pno[pno_by_p[person]].push_back(fno);
            }
        }

        Dfs(0,0,0);
        printf("%d\n", ans);
    }
    return 0;
}
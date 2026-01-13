#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
unordered_map<string, int> pno_by_pname;

const int INF = 0x3f3f3f3f;

int n,m;
int fno_list_by_pno[51][51];
int fnoN_by_pno[51];
ull pset_by_fno[51];
int dp[51];

void Init() {
    pno_by_pname.clear();
    memset(pset_by_fno, 0, sizeof(pset_by_fno));
    memset(dp, 0x3f, sizeof(dp));
    memset(fnoN_by_pno, 0, sizeof(fnoN_by_pno));
}

int Dfs(int pno, int fcnt, ull visit) {
    if(fcnt >= dp[pno]) return INF;
    if(visit == (1ULL<<n)-1) return fcnt;
    if(pno == n) return INF;

    int & ret = dp[pno];
    if(visit & (1ULL<<pno)) return ret = Dfs(pno+1, fcnt, visit); //아무것도 안먹는다.

    for(int i=0; i<fnoN_by_pno[pno]; i++) {
        int fno = fno_list_by_pno[pno][i]; //pno사람이 먹는 음식(fno)
        ret = min(ret, Dfs(pno+1, fcnt+1, visit|pset_by_fno[fno]));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        Init();
        cin >> n >> m;

        string in;
        for(int pno=0; pno<n; pno++) {
            cin >> in;
            pno_by_pname[in] = pno;
        }

        for(int fno=0; fno<m; fno++) {
            int cnt; cin >> cnt;
            for(int i=0; i<cnt; i++) {
                cin >> in;
                int pno = pno_by_pname[in];
                fno_list_by_pno[pno][fnoN_by_pno[pno]++] = fno;
                pset_by_fno[fno] |= (1ULL << pno);
            }
        }

        printf("%d\n", Dfs(0,0,0));
    }
    return 0;
}
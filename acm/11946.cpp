#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
struct Team{
    int cnt, totaltime, tn;
    bool operator<(const Team &rhs) const {
        if(cnt == rhs.cnt) {
            if(totaltime == rhs.totaltime) {
                return tn < rhs.tn;
            } else return totaltime < rhs.totaltime;
        } else return cnt > rhs.cnt;
    }
}team[101];
int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    int tm, tno, pno;
    char res[4];

    int cnt[101][16];
    bool chk[101][16];
    memset(chk, false, sizeof(chk));
    memset(cnt, 0, sizeof(cnt));
    memset(team, 0, sizeof(team));
    for(int i=1; i<=n; i++) team[i].tn = i;
    for(int i=0; i<q; i++) {
        scanf("%d %d %d %s", &tm, &tno, &pno, res);
        if(!strcmp(res, "AC")) {
            if(chk[tno][pno]) continue;
            chk[tno][pno] = true;
            team[tno].totaltime += tm + cnt[tno][pno]*20;
            team[tno].cnt++;
        } else {
            if(chk[tno][pno]) continue;
            cnt[tno][pno]++;
        }
    }
    sort(team+1, team+1+n);
    for(int i=1; i<=n; i++) {
        printf("%d %d %d\n", team[i].tn, team[i].cnt, team[i].totaltime);
    }
    return 0;
}

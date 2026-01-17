#include <bits/stdc++.h>
using namespace std;
const int BLACK = 0;
const int WHITE = 1;
int n;
int board[21][21];
int value[21][21];
int hno_by_co[21][21][2];

int sum_by_hno[21*21*2];
int cnt_by_hno[21*21*2];
int known_by_hno[21*21*2];

void Init(int n) {
    memset(value, 0, sizeof(value));
    memset(known_by_hno, 0, sizeof(known_by_hno));
}

void CalcHnoInfo(int x, int y, int dir) {
    int hint_no = hno_by_co[x][y][dir];
    cnt_by_hno[hint_no]=0;
    known_by_hno[hint_no]=0;
    if(dir == 0) {
        for(int i=y+1; i<n; i++) {
            if(board[x][i] == BLACK) return;
            hno_by_co[x][i][dir] = hint_no;
            cnt_by_hno[hint_no]++;
        }
    }
    else {
        for(int i=x+1; i<n; i++) {
            if(board[i][y] == BLACK) return;
            hno_by_co[i][y][dir] = hint_no;
            cnt_by_hno[hint_no]++;
        }
    }
}

int candidates[46][21][1023]; //[hint_sum][cnt][known_values]
int sum_dp[1023];
int cnt_dp[1023];
int GetSum(int sum_bit) {
    if(sum_bit==0) return 0;
    if(sum_dp[sum_bit]>=0) return sum_dp[sum_bit];

    int & ret = sum_dp[sum_bit];
    ret=0;
    for(int i=1; i<10; i++) {
        if(sum_bit & (1<<i)) ret += i;
    }
    return ret;
}
int GetCnt(int sum_bit) {
    if(sum_bit==0) return 0;
    if(cnt_dp[sum_bit]>=0) return cnt_dp[sum_bit];

    int & ret = cnt_dp[sum_bit];
    ret=0;
    for(int i=1; i<10; i++) {
        if(sum_bit & (1<<i)) ret++;
    }
    return ret;
}
void GenerateCandidates() {
    for(int s=0; s<=1022; s+=2) {
        int sum = GetSum(s);
        int cnt = GetCnt(s);
        for(int known=s; ; known = (known-1)&s) {
            candidates[sum][cnt][known] |= (s & ~known);
            if(known==0) break;
        }
    }
}

inline int GetCandidatesByHno(int hno) {
    return candidates[sum_by_hno[hno]][cnt_by_hno[hno]][known_by_hno[hno]];
}

inline int GetCandidatesByCo(int x, int y) {
    return GetCandidatesByHno(hno_by_co[x][y][0]) & GetCandidatesByHno(hno_by_co[x][y][1]);
}

const int INF = 0x3f3f3f3f;
const int NA = -1;
bool dfs() {
    int mn_len=INF, mn_x=NA, mn_y=NA;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j]==WHITE && value[i][j]==0) {
                int cnt = GetCnt(GetCandidatesByCo(i,j));
                if(mn_len > cnt) {
                    mn_len = cnt;
                    mn_x=i, mn_y=j;
                }
            }
        }
    }

    if(mn_len==0) return false; //No Answer
    if(mn_len==INF) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                printf("%d ", value[i][j]);
            }
            puts("");
        }
        return true;
    }

    int candi = GetCandidatesByCo(mn_x, mn_y)>>1;
    int cnt=1;
    while(candi) {
        if(candi&1) {
            value[mn_x][mn_y] = cnt;
            known_by_hno[hno_by_co[mn_x][mn_y][0]] |= (1<<cnt);
            known_by_hno[hno_by_co[mn_x][mn_y][1]] |= (1<<cnt);
            if(dfs()) return true;
            value[mn_x][mn_y] = 0;
            known_by_hno[hno_by_co[mn_x][mn_y][0]] ^= (1<<cnt);
            known_by_hno[hno_by_co[mn_x][mn_y][1]] ^= (1<<cnt);
        }
        candi>>=1;
        cnt++;
    }
    return false;
}

int main() {
    memset(sum_dp, -1, sizeof(sum_dp));
    memset(cnt_dp, -1, sizeof(sum_dp));
    GenerateCandidates();
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        Init(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> board[i][j];
            }
        }

        int q; cin >> q;
        for(int i=0; i<q; i++) {
            int x,y,dir,sum;
            cin >> x >> y >> dir >> sum;
            x--; y--;
            hno_by_co[x][y][dir] = i;
            sum_by_hno[i] = sum;
            CalcHnoInfo(x,y,dir);
        }

        dfs();
    }
    return 0;
}
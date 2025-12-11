#include <bits/stdc++.h>
using namespace std;
int N, K, M;
int L[51];
double T[51][51];
int Q[51];
const int MASK = (1 << 4) - 1;
double dp[MASK + 1][51];
void Init() {
    for(int i = 0; i <= MASK; i++) {
        for(int j = 0; j <= 50; j++) {
            dp[i][j] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> N >> K >> M;
        for(int i = 0; i < N; i++) {
            cin >> L[i];
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> T[i][j];
            }
        }
        for(int i = 0; i < M; i++) {
            cin >> Q[i];
        }

        Init();
        dp[L[0]][0] = 1.0;
        for(int s = L[0] + 1; s <= K + 4; s++) {
            for(int i = 0; i < N; i++) {
                if(s - L[i] < 0) continue;
                double& res = dp[s & MASK][i];
                res = 0;
                for(int j = 0; j < N; j++) {
                    // j->i
                    res += dp[(s - L[i]) & MASK][j] * T[j][i];
                }
            }
        }
        for(int i = 0; i < M; i++) {
            double sum = 0;
            for(int j = K + 1; j <= K + 4; j++) {
                if(j - L[Q[i]] <= K) {
                    if(dp[j & MASK][Q[i]]) {
                        sum += dp[j & MASK][Q[i]];
                    }
                }
            }
            printf("%.8lf ", sum);
        }
        puts("");
    }
    return 0;
}
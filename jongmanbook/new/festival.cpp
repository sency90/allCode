#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int v[1005];
const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tc; cin >> tc;
    while(tc--) {
        double mn_avg = INF;
        int N,L; cin >> N >> L;
        for(int i=1; i<=N; i++) {
            cin >> v[i];
            v[i]+=v[i-1];
        }
        for (int j = 0; L + j <= N; j++) {
            int mn_sum=INF;
            for (int i = L + j; i <= N; i++) {
                int sum = v[i] - v[i - (L + j)];
                mn_sum = min(mn_sum, sum);
            }
            double avg = (double)mn_sum/(L+j);
            mn_avg = min(mn_avg, avg);
        }
        printf("%.8lf\n", mn_avg);
    }
    return 0;
}
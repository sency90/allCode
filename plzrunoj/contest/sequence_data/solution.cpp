#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 3e5 + 100;

int N, Nr[MAX_N]; ll Ans[MAX_N], MP[MAX_N];
int main() {
    cin >> N; REP(i, N) scanf("%d", &Nr[i]);
    for(int i=0, mul=1; i<N; i++) {
        Ans[0] += 1ll * mul * (i+1) * Nr[i];
        if(i) MP[0] += 1ll * mul * Nr[i];
        mul *= -1;
    }
    for(int i=1, mul=(N%2==0?-1:1); i<N; i++)
        MP[i] = -1 * MP[i-1] - Nr[i] + mul * Nr[(i+N-1)%N];
    for(int i=1, mul=(N%2==0?-1:1); i<N; i++)
        Ans[i] = -1 * Ans[i-1] + MP[i-1] + Nr[i-1] + 1ll * mul * N * Nr[i-1];
    for(int i=0; i<N; i++)
        printf("%lld ", Ans[i]);
    //+1             | -2 +3 -4 ... (-1)^(N+1) * N
    //-1             | +2 -3 +4 ... (-1)^(N+0) * N
    //(-1)^(N+1) * N | +1 -2 +3 ... (-1)^(N+0) * (N-1)
    //x -1 +1 -1 ... (-1)^(N-1)
    return 0;
}

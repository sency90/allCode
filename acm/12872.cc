//d[i][x][y]: 플레이리스트에 i번째 노래까지 넣어서 만들었음.
//그런데, 그 중 x개의 곡은 아직까지 한번도 듣지 않은 곡이고,
//y개는 이미 한번이라도 들어봤던 곡임. (이런 경우의 수를 d[i][x][y]라 하자.)
//
//여기서 그 다음 플레이리스트에 쑤셔넣을 곡이 i+1번째가 되고
//이 i+1번째 되는 곡이 처음듣게 될 곡인지 아니면 이미 들어봤던 곡을 듣게 될지에 대해
//경우를 나눠서 생각해주면 됨.
//
//i+1번째가 처음듣는 곡인 경우: d[i+1][x-1][y+1] = d[i][x][y]*x;
//i+1번째가 이미 들었던 곡인 경우: d[i+1][x][y] = d[i][x][y]*(y-m);
//
//여기서 x or y라는 변수를 없앨 수 있는데, 전곡을 모두 다 들어야 하므로 x+y==n 이기 때문이다.
#include <cstdio>
using namespace std;
const long long MOD = 1000000007LL;
long long d[101][102];
int main() {
    long long n,m,p;
    scanf("%lld%lld%lld",&n,&m,&p);
    d[0][0]=1LL;
    for(int i=0LL; i<p; i++) {
        for(int j=0LL; j<=n; j++) { //j는 이미 들은 곡
            d[i+1][j+1] = (d[i+1][j+1] + (d[i][j]%MOD)*(n-j)) % MOD; //처음 듣게 되는 곡을 들을 때
            if(j-m>0) d[i+1][j] = (d[i+1][j] + (d[i][j]%MOD)*(j-m))%MOD; //이미 들은 곡을 들을 때
        }
    }
    printf("%lld\n", d[p][n]);
    return 0;
}

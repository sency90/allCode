#include <stdio.h>
const long long MOD = 1000000007;
int r[100001][2];

//union-find 자료구조를 모르면 4195번 문제를 반드시 풀어보고 올 것.
int findRoot(int x) {
    if(r[ r[x][0] ][0] == r[x][0]) return r[x][0];

    int n = findRoot(r[x][0]);
    r[x][1] ^= r[ r[x][0] ][1];
    r[x][0] = n;
    return n;
}
int main() {
    int n, m, i;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) {
        r[i][0] = i;
        r[i][1] = 0;
    }

    int a, b, c, x, y, z;
    for(i=1; i<=m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        //문제에서 a-b경로가 반드시 c라는 상태로 이어져 있음을 입력으로 받는다고 했음.
        //그럼 a-b가 이어져 있는건데..
        //이걸 여러개 받다보면 어떤 덩어리들 끼리 묶여있는 형태가 될거 아냐.
        //A그룹, B그룹, C그룹... 이렇게 묶여있겠지.
        //그럼 각 그룹을 대표하는 노드를 지정할 수가 있어
        //어떻게?
        //union-find 자료구조를 쓰면 되는거야.
        //find()함수 만들어서 연결되어있는 것들의 루트를 표현해
        //예를 들면, A그룹에 u,v,w라는 노드가 있는데 여기서 u가 대표노드라고 하면
        //r[u][0], r[v][0], r[w][0]은 모두 u가 되는거지
        //아 그리고 find()만 보이길래 union부분이 어디갔나 했더니 이 반복문 안에 있는 소스코드가 union이구나!!
        //
        x = findRoot(a);
        y = findRoot(b);
        z = (1-c) ^ r[a][1] ^ r[b][1]; //r[a][1]은 a값이 현재 1이나 0으로 배정되어 있는 상태를 의미해. (이 값은 0이나 1 둘중 하나를 갖는거지)
        if(x == y) { //a랑 b랑 같은 그룹이 아니면
            if(z == 1) break; //z는 절대 1일 수 없음. z가 1이면 답은 무조건 0일 수밖에 없다.
            else continue;
        }
        r[x][0] = y;
        r[x][1] = z;
    }

    if(i<=m) {
        puts("0");
        return 0;
    }

    int cnt = -1;
    for(i=1; i<=n; i++) {
        if(i == r[i][0]) cnt++;
    }

    long long ans = 1;
    for(i=1; i<=cnt; i++) {
        ans *= 2;
        ans %= MOD;
    }
    printf("%lld", ans);
    return 0;
}

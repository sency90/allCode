#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <limits.h>
//d[i][c]: a[0]부터 a[i]까지의 앱을 어떤건 삭제하고 어떤건 삭제하지 않도록
//고려했을 때, 비용 c를 들여서 만들어 낼 수 있는 최대 메모리 크기
using namespace std;
int n, m;
struct App {
    int m, c;
}a[101];
int ans = INT_MAX;
int d[101][10001];
int f(int x, int co) {
    if(d[x][co]!=-1) return d[x][co];
    if(x==0) return d[x][co]=0;
    else if(x==1) {
        if(co == 0) {
            if(a[x].c != 0) return d[x][co] = 0;
            else return d[x][co] = a[x].m;
        } else if(co>=a[x].c) return d[x][co] = a[x].m;
        else return d[x][co] = f(x, co-1);
    }


    int tmp;
    if(co-a[x].c >= 0) {
        tmp = max(f(x-1, co), f(x-1, co-(a[x].c))+a[x].m);
    } else tmp = f(x-1, co);

    if(tmp >= m) {
        if(ans > co) ans = co;
    }
    return d[x][co] = tmp;
}
int main() {
    memset(d, -1, sizeof(d));
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i].m);
    }

    a[0].m = 0;
    a[0].c = 0;
    int sum=0;
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i].c);
        sum += a[i].c;
    }
    for(int i=0; i<=sum; i++) {
        f(n, i);
    }
    printf("%d", ans);
    return 0;
}

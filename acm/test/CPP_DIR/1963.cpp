#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
queue<int> q;
int d[10001];
bool isP[10001], chk[10001];
char str[5];
int chg(int num, int idx, int j) {
    if(idx==0 && j==0) return -1;
    sprintf(str, "%d", num);
    str[idx] = j+'0';
    num = atoi(str);
    if(isP[num]) return num;
    else return -1;
}
int main() {
    int t, n, m;
    memset(isP, true, sizeof(isP));
    isP[0] = false; isP[1] = false;
    for(int i=2; i<=10000; i++) {
        if(!isP[i]) continue;
        for(int j=i*i; j<=10000; j+=i) {
            isP[j] = false;
        }
    }
    int next, now;
    scanf("%d", &t);
    while(t--) {
        memset(chk, false, sizeof(chk));
        memset(d, -1, sizeof(d));
        scanf("%d %d", &n, &m);
        d[n] = 0;
        chk[n] = true;
        q.push(n);
        while(!q.empty()) {
            now = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                for(int j=0; j<=9; j++) {
                    next = chg(now, i, j);
                    if(next != -1) {
                        if(isP[next] && !chk[next]) {
                            chk[next] = true;
                            d[next] = d[now]+1;
                            q.push(next);
                        }
                    }
                }
            }
        }
        if(d[m] != -1) printf("%d\n", d[m]);
        else puts("Impossible");
    }
    return 0;
}

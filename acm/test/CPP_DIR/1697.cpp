#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
queue<int> q;
int d[100001];
bool chk[100001];
int main() {
    int n, k, i;
    memset(chk, false, sizeof(chk));
    scanf("%d %d", &n, &k);

    q.push(n);
    chk[n] = true;
    while(true) {
        i = q.front(); q.pop();
        if(i==k) break;
        if(i-1 >= 0) {
            if(!chk[i-1]) {
                q.push(i-1);
                chk[i-1] = true;
                d[i-1] = d[i]+1;
            }
        }
        if(i+1 <= 100000) {
            if(!chk[i+1]) {
                q.push(i+1);
                chk[i+1] = true;
                d[i+1] = d[i]+1;
            }
        }
        if(i*2 <= 100000) {
            if(!chk[i*2]) {
                q.push(i*2);
                chk[i*2] = true;
                d[i*2] = d[i]+1;
            }
        }
    }
    printf("%d", d[k]);
    return 0;
}

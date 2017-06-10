#include <iostream>
#include <cstring>
using namespace std;
int coin[100], cnt[100];
int d[10001][100];
int f(int m, int idx) {
    if(idx == 0) {
        if(m == 0) return 1;
        else return 0;
    }
    int &ret = d[m][idx];
    if(ret != -1) return ret;
    else ret = 0;

    for(int i=0; i<=cnt[idx]; i++) {
        if(m < coin[idx]*i) break;
        ret += f(m-coin[idx]*i, idx-1);
    }
    return ret;
}
int main() {
    //freopen("input.txt", "r", stdin);
    memset(d, -1, sizeof(d));
    int m, cc;
    scanf("%d %d", &m, &cc);
    for(int i=1; i<=cc; i++) {
        scanf("%d %d", &coin[i], &cnt[i]);
    }
    printf("%d", f(m, cc));
    return 0;
}

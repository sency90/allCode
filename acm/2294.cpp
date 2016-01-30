#include <stdio.h>
#include <string.h>

short coin[100];
short m[10001];

int main() {
    memset(coin, 0, sizeof(coin));
    memset(m, 0, sizeof(m));

    short n, k;
    scanf("%hd %hd", &n, &k);

    for(short i=0; i<n; i++) {
        scanf("%hd", &coin[i]);
    }

    short temp = k/coin[0];
    for(short i=0; i<=temp; i++) {
        m[i*coin[0]] = i;
    }

    for(short i=1; i<n; i++) {
        for(short j=coin[i]; j<k+1; j++) {
            if(m[j] == 0 || m[j-coin[i]]+1 < m[j]) {
                if(m[j-coin[i]] != 0 || j%coin[i] == 0) {
                    m[j] = m[j-coin[i]]+1;
                }
            }
        }
    }

    if(m[k] == 0) printf("%d\n", -1);
    else printf("%hd\n", m[k]);

    return 0;
}

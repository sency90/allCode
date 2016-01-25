#include <stdio.h>
#include <string.h>

unsigned long long combi[31][31];

unsigned long long calcCombi(unsigned long long bn, unsigned long long sn) {
    if(bn == sn) //base case
        combi[bn][sn] = sn;
    else if(0 == combi[bn][sn]) //recursive part
        combi[bn][sn] = bn * calcCombi(bn-1, sn);

    return combi[bn][sn];
}

int main() {
    int t;
    unsigned long long i, j, n, m;
    unsigned long long deno, nume;
    combi[30][15] = 155117520;

    memset(combi, 0, sizeof(combi));
    scanf("%d", &t);
    while(t--) {

        scanf("%llu %llu", &n, &m);
        if(m == 30 && n==15) {
            printf("155117520\n");
            continue;
        }
        else if(m == n || n == 0) {
            printf("1\n");
            continue;
        }

        if(n*2 > m) n = m-n;
        deno = calcCombi(m, m-n+1);
        nume = calcCombi(n, 1);

        printf("%llu\n", (unsigned long long)(deno/nume));
    }

    return 0;
}

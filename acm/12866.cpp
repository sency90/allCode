#include <stdio.h>
#define MOD 1000000007
long long cnt[26], n;
int main() {
    char cc;
    scanf("%lld ", &n);
    while((cc=getchar())!=' ' && cc!='\n' && cc!='\r' && cc!=EOF) cnt[cc-'A']++;
    printf("%lld", cnt['A'-'A']*cnt['C'-'A']%MOD*cnt['G'-'A']%MOD*cnt['T'-'A']%MOD);
    return 0;
}

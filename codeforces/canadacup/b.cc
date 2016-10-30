#include <cstdio>
using namespace std;
typedef unsigned long long ull;
ull chg(char c) {
    if(c=='f') return 1ULL;
    else if(c=='e') return 2ULL;
    else if(c=='d') return 3ULL;
    else if(c=='a') return 4ULL;
    else if(c=='b') return 5ULL;
    else return 6ULL;
}
int main() {
    ull d;
    char c[2];
    scanf("%llu%s",&d,c);
    ull tmp=0ULL;
    if(d&1ULL) tmp=chg(c[0]);
    else tmp=chg(c[0])+7ULL;
    printf("%llu\n", (ull)((d-1ULL)/4ULL)*16ULL + tmp);
    return 0;
}

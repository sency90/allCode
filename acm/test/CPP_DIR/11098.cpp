#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct Player{
    int amt;
    char name[21];
}p[100];

bool cmp(Player a, Player b) {
    return a.amt > b.amt;
}

int main() {
    int n, t, i; scanf("%d", &t);
    while(t--) {
        memset(p, 0, sizeof(p));
        scanf("%d", &n);
        for(i=0; i<n; i++) {
            scanf("%d %s", &p[i].amt, p[i].name);
        }
        sort(p, p+n, cmp);
        printf("%s\n", p[0].name);
    }
    return 0;
}

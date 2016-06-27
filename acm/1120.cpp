#include <stdio.h>
#include <cstring>
using namespace std;
char sa[51], sb[51];
int main() {
    scanf("%s %s", sa, sb);
    int alen = strlen(sa), blen = strlen(sb);
    int cnt, mn=0x3f3f3f3f;
    for(int i=0; i<=blen-alen; i++) {
        cnt = 0;
        for(int j=0; j<alen; j++) {
            if(sa[j] != sb[i+j]) cnt++;
        }
        if(mn > cnt) mn = cnt;
    }
    printf("%d", mn);
    return 0;
}

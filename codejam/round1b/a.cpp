#include <stdio.h>
#include <cstring>
using namespace std;
char str[2001];
int cnt[26];
int numcnt[10];
int main() {
    int t, len;
    freopen("/Users/lian/allCode/codejam/round1b/abin.txt", "r", stdin);
    freopen("/Users/lian/allCode/codejam/round1b/about.txt", "w", stdout);
    scanf("%d ", &t);
    for(int k=1; k<=t; k++) {
        scanf("%s", str);
        len = strlen(str);
        memset(cnt, 0, sizeof(cnt));
        memset(numcnt, 0, sizeof(numcnt));
        for(int i=0; i<len; i++) {
            cnt[str[i]-'A']++;
        }
        numcnt[0] = cnt['Z'-'A'];
        cnt['E'-'A'] -= cnt['Z'-'A'];
        cnt['R'-'A'] -= cnt['Z'-'A'];
        cnt['O'-'A'] -= cnt['Z'-'A'];

        numcnt[2] = cnt['W'-'A'];
        cnt['T'-'A'] -= cnt['W'-'A'];
        cnt['O'-'A'] -= cnt['W'-'A'];

        numcnt[4] = cnt['U'-'A'];
        cnt['F'-'A'] -= cnt['U'-'A'];
        cnt['O'-'A'] -= cnt['U'-'A'];
        cnt['R'-'A'] -= cnt['U'-'A'];

        numcnt[6] = cnt['X'-'A'];
        cnt['S'-'A'] -= cnt['X'-'A'];
        cnt['I'-'A'] -= cnt['X'-'A'];

        numcnt[8] = cnt['G'-'A'];
        cnt['E'-'A'] -= cnt['G'-'A'];
        cnt['I'-'A'] -= cnt['G'-'A'];
        cnt['H'-'A'] -= cnt['G'-'A'];
        cnt['T'-'A'] -= cnt['G'-'A'];

        numcnt[1] = cnt['O'-'A'];
        cnt['N'-'A'] -= cnt['O'-'A'];
        cnt['E'-'A'] -= cnt['O'-'A'];

        numcnt[3] = cnt['T'-'A'];
        cnt['H'-'A'] -= cnt['T'-'A'];
        cnt['R'-'A'] -= cnt['T'-'A'];
        cnt['E'-'A'] -= (cnt['T'-'A']*2);

        numcnt[5] = cnt['F'-'A'];
        cnt['I'-'A'] -= cnt['F'-'A'];
        cnt['V'-'A'] -= cnt['F'-'A'];
        cnt['E'-'A'] -= cnt['F'-'A'];

        numcnt[7] = cnt['S'-'A'];
        cnt['E'-'A'] -= cnt['S'-'A']*2;
        cnt['V'-'A'] -= cnt['S'-'A'];
        cnt['N'-'A'] -= cnt['S'-'A'];

        numcnt[9] = cnt['I'-'A'];
        printf("Case #%d: ", k);
        for(int i=0; i<10; i++) {
            for(int j=0; j<numcnt[i]; j++) {
                printf("%d", i);
            }
        }
        puts("");
    }
    fclose(stdin);
    return 0;
}

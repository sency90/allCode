#include <stdio.h>
#include <cstring>
using namespace std;
int main() {
    int sum = 0, cnt[10];
    char c;
    memset(cnt, 0, sizeof(cnt));
    while((c=getchar())!='\n' && c!=EOF) {
        sum += c-'0';
        cnt[c-'0']++;
    }
    if(cnt[0] && sum%3==0) {
        for(int i=9; i>=0; i--) {
            for(int j=0; j<cnt[i]; j++) {
                printf("%d", i);
            }
        }
    } else printf("-1");
    return 0;
}

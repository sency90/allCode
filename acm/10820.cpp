#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char c = 0, cnt[4];
    while(c!=EOF) {
        memset(cnt, 0, sizeof(cnt));
        while((c = getchar())!='\n' && c!=EOF) {
            if(islower(c)) cnt[0]++;
            else if(isupper(c)) cnt[1]++;
            else if(isdigit(c)) cnt[2]++;
            else if(isspace(c)) cnt[3]++;
        }
        if(c==EOF) break;
        for(int i=0; i<4; i++) printf("%d ", cnt[i]);
        printf("\n");
    }
    return 0;
}

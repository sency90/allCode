#include <stdio.h>
#include <string.h>
bool x[26];
int main() {
    int t, sum;
    char c;
    scanf("%d", &t);
    getchar();
    while(t--) {
        sum = 0;
        memset(x, false, sizeof(x));
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            x[c-'A']=true;
        }
        for(int i=0; i<26; i++) {
            if(!x[i]) sum += i+'A';
        }
        printf("%d\n", sum);
    }
    return 0;
}

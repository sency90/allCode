#include <stdio.h>
#include <cctype>
#include <cstring>
using namespace std;
int sum, cnt[26];
int main() {
    char c;
    while(true) {
        sum=0;
        memset(cnt, 0, sizeof(cnt));
        while((c=getchar())!='\n'&&c!='\r') {
            if(c=='#') return 0;
            if(islower(c)) {
                cnt[c-'a']=1;
            } else if(isupper(c)) {
                cnt[c-'A']=1;
            }
        }
        for(int i=0; i<26; i++) {
            sum+=cnt[i];
        }
        printf("%d\n", sum);
    }
}

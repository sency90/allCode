#include <stdio.h>
#include <cctype>
using namespace std;
char c, s[26];
int main() {
    int n, cnt, k;
    scanf("%d ", &n);
    for(int i=0; i<n; i++) {
        cnt=0; k=0;
        while((c=getchar())!='\n'&&c!=EOF&&c!='\r') {
            s[k++]=c;
            if(isupper(c)) c=c-'A'+'a';
            if(c=='b') cnt--;
            else if(c=='g') cnt++;
        }
        s[k]='\0';
        printf("%s is ", s);
        if(cnt<0) puts("A BADDY");
        else if(cnt>0) puts("GOOD");
        else puts("NEUTRAL");
    }
    return 0;
}

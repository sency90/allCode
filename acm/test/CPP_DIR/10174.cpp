#include <stdio.h>
#include <cstring>
#include <cctype>
using namespace std;
char s[101], c;
int main() {
    int n, l, r, k;
    bool isBrk;
    scanf("%d ", &n);
    for(int i=0; i<n; i++) {
        k=0;
        while((c=getchar())!='\n'&&c!='\r'&&c!=EOF) {
            if(isupper(c)) c=c-'A'+'a';
            s[k++]=c;
        }
        s[k]='\0';
        isBrk = false;
        l=0; r=strlen(s)-1;
        while(l<=r) {
            if(s[l++]!=s[r--]) {
                puts("No");
                isBrk = true;
                break;
            }
        }
        if(!isBrk) puts("Yes");
    }
    return 0;
}

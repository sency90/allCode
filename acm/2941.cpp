#include <stdio.h>
#include <cstring>
#include <cctype>
using namespace std;
char s[101];
int main() {
    scanf("%s", s);
    int len = strlen(s), cnt=0;
    for(int i=0; i<len; i++) {
        if(s[i+1]!='\0') {
            if(s[i]=='=' || s[i]=='-') continue;

            if(s[i+2]!='\0') {
                if(s[i]=='d' && s[i+1]=='z' && s[i+2]=='=') {
                    i+=2;
                    cnt++;
                    continue;
                }
            }

            if(s[i]=='c' || s[i]=='s' || s[i]=='z') {
                if(s[i+1]=='=') i++;
                else if(s[i+1]=='-') i++;
            } else if(s[i]=='d') {
                if(s[i+1]=='-') i++;
            } else if(s[i]=='l' || s[i]=='n') {
                if(s[i+1]=='j') i++;
            }
        }
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}

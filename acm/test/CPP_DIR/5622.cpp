#include <stdio.h>
#include <cstring>
using namespace std;
int main() {
    char str[16];
    scanf("%s", str);
    int len = strlen(str), ans=0;
    for(int i=0; i<len; i++) {
        if(str[i]=='Z') str[i]='Y';
        if((str[i]-'A')/3>5) ans+=(str[i]-'A'-1)/3+3;
        else ans+=(str[i]-'A')/3+3;
    }
    printf("%d", ans);
    return 0;
}

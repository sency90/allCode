#include <stdio.h>
#include <cstring>
using namespace std;
char str[100001];
int main() {
    bool isIn = false;
    int d=0, ans=0, l=0, r=0;
    scanf("%s", str);
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        if(str[i]=='(') {
            d++; l++;
        } else {
            d--; r++;
        }
        if(d==-2) {
            if(isIn) {
                puts("0");
                return 0;
            }
            isIn = true;
            ans+=r-1;
            r=0; d=0;
        }
        if(d<2) l=0;
    }
    if(d==0) printf("%d", ans);
    else if(d==2) printf("%d", l+ans);
    else puts("0");
    return 0;
}

#include <cstdio>
using namespace std;
int chg(char x) { return x-'0'; }
char s[6], h[3], m[3];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    h[0]=s[0];h[1]=s[1];m[0]=s[3];m[1]=s[4];
    if(n==24) {
        if(h[0]-'0'>=3 || ((h[0]-'0')==2 && h[1]-'0'>=4)) {
            h[0]='0';
        }
        if(chg(m[0])>=6) m[0]='1';
    } else {
        if(chg(h[1])!=0) {
            if(chg(h[0])>=2 || (chg(h[0])==1 && chg(h[1])>=3)) h[0]='0';
        } else {
            if(chg(h[0])>=2) {
                h[0]='1';
            } else if(chg(h[0])==0) {
                h[0]='1';
            }
        }
        if(chg(m[0])>=6) m[0]='1';
    }
    printf("%s:%s\n",h,m);
    return 0;
}

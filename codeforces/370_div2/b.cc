#include <cstdio>
#include <cstring>
using namespace std;
char s[100001];
int l,r,u,d;
int ABS(int x) { return x<0?-x:x; }
int main() {
    scanf("%s", s);
    int len=strlen(s);
    if(len&1) {
        puts("-1");
        return 0;
    }
    for(int i=0; i<len; i++) {
        if(s[i]=='L') l++;
        else if(s[i]=='R') r++;
        else if(s[i]=='D') d++;
        else u++;
    }
    printf("%d", (ABS(l-r)+ABS(u-d))/2);
    return 0;
}

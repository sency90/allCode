#include <stdio.h>
#include <map>
using namespace std;
map<char, int> mo;
char s[1005], chk[4][14];
int f(char a, char b) {
    return (a-'0')*10+(b-'0');
}
int main() {
    mo['P']=0; mo['K']=1; mo['H']=2; mo['T']=3;
    scanf("%s", s);
    for(int i=0; s[i]; i+=3) {
        int x=mo[s[i]], y=f(s[i+1],s[i+2]);
        if(!chk[x][y]) chk[x][y] = true;
        else {
            puts("GRESKA");
            return 0;
        }
    }
    for(int i=0; i<4; i++) {
        int ans=0;
        for(int j=1; j<=13; j++) {
            if(!chk[i][j]) ans++;
        }
        printf("%d ", ans);
    }
    return 0;
}

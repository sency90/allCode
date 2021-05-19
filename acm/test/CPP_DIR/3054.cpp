#include <stdio.h>
#include <cstring>
using namespace std;
char s[16], p[5][61];
void draw(int y, char c, bool isStar) {
    char r;
    if(isStar) r = '*';
    else r = '#';
    for(int i=0; i<5; i++) {
        for(int j=y; j<y+5; j++) {
            if(i==0 || i==4) {
                if(j==y+2) {
                    p[i][j]=r;
                }
            } else if(i==1 || i==3) {
                if(j%2==1) {
                    p[i][j]=r;
                }
            } else if(i==2) {
                if(j%2==0) {
                    if(p[i][j]=='*' && (j==y+4||j==y)) continue;
                    if(j==y+2) p[i][j] = c;
                    else p[i][j]=r;
                }
            }
        }
    }
}
int main() {
    scanf("%s", s);
    int len = strlen(s);
    memset(p, '.', sizeof(p));
    for(int i=0; i<len; i++) {
        if(i%3==2) draw(i*4,s[i],true);
        else draw(i*4,s[i],false);
    }
    for(int i=0; i<5; i++) {
        for(int j=0; j<=len*4; j++) {
            printf("%c", p[i][j]);
        }
        puts("");
    }
    return 0;
}

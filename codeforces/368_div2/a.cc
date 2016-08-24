#include <stdio.h>
char v[100][100][2];
int main() {
    int r,c;
    scanf("%d%d",&r,&c);
    bool isColor = false;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            scanf("%s", v[i][j]);
            if(v[i][j][0]!='W'&&v[i][j][0]!='B') isColor = true;
        }
    }
    if(isColor) puts("#Color");
    else puts("#Black&White");
    return 0;
}

#include <stdio.h>
char str[10][11];
int main() {
    int n, m, j;
    bool hasAns = true;
    char c;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%s", str[i]);
    }getchar();
    for(int i=0; i<n; i++) {
        j=0;
        while((c=getchar())!='\n' && c!=EOF && c!='\r') {
            if(c!=str[i][j++/2]) {
                hasAns = false;
            }
        }
    }
    if(hasAns) puts("Eyfa");
    else puts("Not Eyfa");
    return 0;
}

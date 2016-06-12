#include <stdio.h>
#include <cstring>
using namespace std;
char s[201];
int main() {
    int n, cnt=0;
    scanf("%d%s", &n,s);
    int len = strlen(s);
    int r = len/n, c = n;
    char v[r][c];
    for(int i=0; i<r; i++) {
        if(i%2==0) {
            for(int j=0; j<c; j++) {
                v[i][j]=s[cnt++];
            }
        } else {
            for(int j=c-1; j>=0; j--) {
                v[i][j]=s[cnt++];
            }
        }
    }
    for(int i=0; i<c; i++) {
        for(int j=0; j<r; j++) {
            putchar(v[j][i]);
        }
    }
    return 0;
}

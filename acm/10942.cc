#include <cstdio>
#include <cstring>
using namespace std;
char ispal[2001][2001];
int v[2001];
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    memset(ispal,'0',sizeof(ispal));
    for(int i=1; i<=n; i++) ispal[i][i]='1';
    for(int i=1; i+1<=n; i++) {
        if(v[i]==v[i+1]) ispal[i][i+1]='1';
        else ispal[i][i+1]='0';
    }
    for(int j=2; j<n; j++) {
        for(int i=1; i+j<=n; i++) {
            if(ispal[i+1][i+j-1]=='1' && v[i]==v[i+j]) ispal[i][i+j]='1';
            else ispal[i][i+j]='0';
        }
    }

    int m,x,y; scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d%d",&x,&y);
        printf("%c\n",ispal[x][y]);
    }
    return 0;
}


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[1024],b[1024];
int d[2][1024];
int main() {
    a[0]=b[0]=' ';
    scanf("%s%s",a+1,b+1);
    int t=0,i,j;
    for(i=1; a[i]; i++) {
        for(j=1; b[j]; j++) {
            if(a[i]==b[j]) d[t][j] = max(d[t][j-1], d[t^1][j-1]+1);
            else d[t][j] = max(d[t][j-1], d[t^1][j]);
        }
        t^=1;
    }
    printf("%d", max(d[t][j-1],d[t^1][j-1]));
    return 0;
}

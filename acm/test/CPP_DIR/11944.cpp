#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
char str[5];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    sprintf(str, "%d", n);
    int len = strlen(str);
    if(len*n > m) {
    for(int i=0; i<m; i++) {
        printf("%c", str[i%len]);
    }
    } else {
        for(int i=0; i<n; i++) {
            printf("%d", n);
        }
    }
    return 0;
}

#include <cstdio>
using namespace std;
char s[200][201];
int main() {
    int n; scanf("%d", &n);
    int lim = 2*n-1;

    for(int i=0; i<lim; i++) {
        for(int j=0; j<lim; j++) s[i][j] = '*';
        s[i][lim] = 0;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            s[lim-1-i][j] = s[i][j] = ' ';
            s[i][lim-1-j] = s[lim-1-i][lim-1-j] = 0;
        }
    }

    for(int i=0; i<lim; i++) printf("%s\n", s[i]);
    return 0;
}

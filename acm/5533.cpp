#include <stdio.h>
#include <cstring>
using namespace std;
int s[200], sc[200][3], cnt[101];
int main() {
    int n;
    scanf("%d", &n);
    memset(s, 0, sizeof(s));
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d", &sc[i][j]);
        }
    }
    for(int i=0; i<3; i++) {
        memset(cnt, 0, sizeof(cnt));
        for(int j=0; j<n; j++) {
            cnt[sc[j][i]]++;
        }
        for(int j=0; j<n; j++) {
            if(cnt[sc[j][i]]==1) s[j] += sc[j][i];
        }
    }
    for(int i=0; i<n; i++) {
        printf("%d\n", s[i]);
    }
    return 0;
}

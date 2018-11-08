#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
char correct[8][8] = {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'}
};
char chess[51][51];
int main() {
    int mn = 0x3f3f3f3f;
    int n, m; scanf("%d%d", &n,&m);
    for(int i=0; i<n; i++) {
        scanf("%s", chess[i]);
    }
    for(int i=0; i<=n-8; i++) {
        for(int j=0; j<=m-8; j++) {
            int cnt=0, rcnt=0;
            for(int u=0; u<8; u++) {
                for(int v=0; v<8; v++) {
                    if(chess[i+u][j+v] != correct[u][v]) cnt++;
                    else rcnt++;
                }
            }
            mn = min({mn, cnt, rcnt});
        }
    }
    printf("%d", mn);
    return 0;
}

#include <cstdio>
using namespace std;
int v[1001][1001];
int main() {
    int n,m,tcnt=0;
    scanf("%d%d",&n,&m);
    for(int i=0, cnt=0; i<n; i++, cnt=0) {
        for(int j=0; j<m; j++) {
            scanf("%d",&v[i][j]);
            if(!v[i][j]) cnt++;
            else {
                tcnt+=cnt;
                cnt=0;
            }
        }
    }

    for(int i=0, cnt=0; i<n; i++, cnt=0) {
        for(int j=m-1; j>=0; j--) {
            if(!v[i][j]) cnt++;
            else {
                tcnt+=cnt;
                cnt=0;
            }
        }
    }

    for(int j=0, cnt=0; j<m; j++, cnt=0) {
        for(int i=0; i<n; i++) {
            if(!v[i][j]) cnt++;
            else {
                tcnt+=cnt;
                cnt=0;
            }
        }
    }

    for(int j=0, cnt=0; j<m; j++, cnt=0) {
        cnt=0;
        for(int i=n-1; i>=0; i--) {
            if(!v[i][j]) cnt++;
            else {
                tcnt+=cnt;
                cnt=0;
            }
        }
    }
    printf("%d\n", tcnt);
    return 0;
}

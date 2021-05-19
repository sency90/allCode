#include <cstdio>
using namespace std;
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int h,w,n;
        scanf("%d%d%d",&h,&w,&n);
        int cnt=0;
        for(int j=1; j<=w; j++) {
            for(int i=1; i<=h; i++) {
                cnt++;
                if(cnt==n) {
                    printf("%d%02d\n", i,j);
                    break;
                }
            }
            if(cnt==n) break;
        }
    }
    return 0;
}

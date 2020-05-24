#include <cstdio>
#include <cstring>
using namespace std;
int v[200001];
bool chk[200001];
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n; scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }
        for(int i=0; i<n; i++) {
            chk[(i+v[i]+int(1e9))%n] = true;
        }
        bool good = true;
        for(int i=0; i<n; i++) {
            if(!chk[i]) {
                good = false;
                break;
            }
        }

        if(good) puts("YES");
        else puts("NO");

        memset(chk,false,sizeof(chk));
    }
    return 0;
}

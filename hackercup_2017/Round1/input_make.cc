#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
const int mod=1e9;
int main() {
    freopen("b_input.txt", "w", stdout);
    srand(time(0));
    int tc;
    scanf("%d",&tc);
    printf("%d\n", tc);
    while(tc--) {
        int n=50;
        int r=rand()%mod+1;
        printf("%d %d\n",n,r);
        for(int i=0; i<n; i++) {
            int x=rand()%(mod+1), y=rand()%(mod+1);
            printf("%d %d\n", x,y);
        }
    }
    return 0;
}

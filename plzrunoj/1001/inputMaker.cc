#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    freopen("./in.txt","w",stdout);
    int n=1000, tc=10;
    while(tc--) {
        srand(time(0));
        printf("%d\n", n);
        for(int i=0; i<n; i++) {
            printf("%d ", rand()%10001*(i+1)%10001);
        }
        puts("");
        if(tc==1) n=1;
        else n-=100;
    }
    return 0;
}

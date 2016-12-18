#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    freopen("in.txt", "w", stdout);
    srand(time(0));
    int n,l,r;
    for(int i=0; i<10000; i++) {
        n=rand()%100+1;
        l=rand()%n+1;
        r=rand()%n+1;
        printf("%d %d %d\n", n,l,r);
    }
    return 0;
}

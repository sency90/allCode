#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    freopen("/Users/lian/allCode/codeforces/366_div2/input.txt", "w", stdout);
    int n = 300000, m=300000, x,y;
    printf("%d %d\n", 1, 300000);
    for(int i=1; i<n; i++) {
        x = rand()%3+1;
        if(x==3) y = rand()%i+1;
        else y = rand()%300000+1;
        printf("%d %d\n", x, y);
    }
    return 0;
}

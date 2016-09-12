#include <stdio.h>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    srand(time(0));
    freopen("input.txt", "w", stdout);
    int n=100000;
    printf("%d\n", n);
    for(int i=0; i<n; i++) {
        printf("%d ", rand()%1000000000+1);
    }
    fclose(stdout);
    return 0;
}

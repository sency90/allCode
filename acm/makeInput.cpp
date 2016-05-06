#include <stdio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    int n = 1000000;
    freopen("output.txt", "w", stdout);
    srand(time(0));
    printf("%d\n", n);
    for(int i=0; i<n; i++) {
        printf("%d ", rand()%n+1);
    }
    fclose(stdout);
    return 0;
}

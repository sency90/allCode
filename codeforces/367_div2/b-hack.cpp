#include <stdio.h>
#include <cstdlib>
using namespace std;
int main() {
    int n = 100000;
    puts("100000");
    for(int i=0; i<n-1; i++) {
        printf("%d ", rand()%99999+1);
    }
    printf("99999\n100000\n");
    for(int i=0; i<n; i++) {
        printf("%d\n", rand()%99999+1);
    }
    return 0;
}

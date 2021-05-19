#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    freopen("input.txt", "w", stdout);
    for(int i=1; i<=10000; i++) {
        for(int j=1; j<=min(i,100); j++) {
            printf("%d %d\n", i,j);
        }
    }
    return 0;
}

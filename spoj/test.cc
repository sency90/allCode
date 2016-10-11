#include <cstdio>
using namespace std;
int main() {
    int n;
    while(~scanf("%d", &n)) {
        if(n==42) return 0;
        printf("%d\n", n);
    }
    return 0;
}

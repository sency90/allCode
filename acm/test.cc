#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int n[2];
    memset(n, 0xc0, sizeof(n));
    printf("%d", n[0]);
    return 0;
}

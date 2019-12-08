#include <cstdio>
#include <cstdlib>
using namespace std;
char cmd[300];
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        sprintf(cmd, "./bin/1463-3 << %d", n);
        system(cmd);
    }
    return 0;
}

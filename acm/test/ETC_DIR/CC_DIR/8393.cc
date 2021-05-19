#include <cstdio>
using namespace std;
int main() {
    int n; scanf("%d", &n);
    int sum=0;
    for(int i=1; i<=n; i++) sum +=i;
    printf("%d\n", sum);
    return 0;
}

#include <cstdio>
using namespace std;
int main() {
    int n; scanf("%d", &n);
    double sum = 0;
    for(int i=1; i<=n; i++) {
        sum += 1.0/i;
    }
    printf("%0.8lf", sum);
}

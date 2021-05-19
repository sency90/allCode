#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(const int a, const int b) {
    return a > b;
}
int main() {
    int p[1000], sum=0;
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &p[i]);
    }
    sort(p, p+n, cmp);
    for(int i=0; i<n; i++) {
        sum += p[i]*(i+1);
    }
    printf("%d", sum);
    return 0;
}

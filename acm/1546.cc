#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int v[1001];
int main() {
    int mx = 0;
    int n; scanf("%d", &n);
    for(int i=0; i<n ;i++) {
        scanf("%d", &v[i]);
        mx = max(mx, v[i]);
    }
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += v[i]*100;
    }
    printf("%.3lf", (double(sum))/mx/n);
    return 0;
}

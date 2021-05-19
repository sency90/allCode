#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <limits.h>
using namespace std;
int v[100001], mx = INT_MIN;
bool isIn[100001];
int f(int x) {
    if(x == 1) {
        if(mx < v[1]) mx = v[1];
        return v[1];
    }
    if(isIn[x]) return v[x];

    int temp = f(x-1)+v[x];
    v[x] = max(temp, v[x]);
    isIn[x] = true;
    if(mx < v[x]) mx = v[x];
    return v[x];
}
int main() {
    memset(isIn, false, sizeof(isIn));
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    } f(n);
    printf("%d", mx);
    return 0;
}

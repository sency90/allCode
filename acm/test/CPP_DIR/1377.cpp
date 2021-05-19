#include <stdio.h>
#include <algorithm>
using namespace std;
struct A{
    int x, idx;
    bool operator<(const A &rhs) const {
        return x < rhs.x;
    }
}a[500000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i].x);
        a[i].idx = i;
    }
    stable_sort(a, a+n);
    int max = 1, tmp;
    for(int i=0; i<n; i++) {
        if(i >= a[i].idx) continue;
        else tmp = a[i].idx-i+1;
        if(max < tmp) max = tmp;
    }
    printf("%d", max);
    return 0;
}

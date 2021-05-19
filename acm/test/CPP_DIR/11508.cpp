#include <stdio.h>
#include <algorithm>
using namespace std;
int v[100001];
bool cmp(const int& lhs, const int& rhs) {
    return lhs > rhs;
}
int main() {
    int n, sum=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
        sum+=v[i];
    }
    sort(v, v+n, cmp);
    int x=n/3;
    for(int i=2,j=0; j<x; i+=3,j++) {
        sum-=v[i];
    }
    printf("%d", sum);
    return 0;
}

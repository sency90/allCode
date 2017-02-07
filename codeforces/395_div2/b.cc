#include <cstdio>
#include <algorithm>
using namespace std;
int v[200001];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    int lim=n/2;
    for(int i=0; i<lim; i+=2) {
        swap(v[i],v[n-i-1]);
    }
    for(int i=0; i<n; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;
int v[100001];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v, v+n);
    for(int i=0; i<n-2; i++) {
        if(v[i]+v[i+1]>v[i+2]) return 0&puts("YES");
    }
    puts("NO");
    return 0;
}

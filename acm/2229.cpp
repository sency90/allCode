#include <stdio.h>
#include <cstring>
using namespace std;
int v[1001];
int d[1001];
int n;
int main() {
    int n;
    scanf("%d", &n);
    memset(d, 0, sizeof(d));
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    for(int i=1; i<=n; i++) {
        d[i] = d[i-1];
        int mx = v[i];
        int mn = v[i];
        for(int j=i-1; j>=1; j--) {
            if(mx < v[j]) mx = v[j];
            if(mn > v[j]) mn = v[j]
        }
    }
    return 0;
}


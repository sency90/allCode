#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1000];
bool chk[1000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    for(int i=0; i<n; i++) s[i] += a[i];
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            chk[sum-(s[j]+s[i])] = false;
        }
    }
    return 0;
}

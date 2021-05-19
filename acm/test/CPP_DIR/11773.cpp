#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    int tmp = max(n, (m+1)/2);
    for(int i=1; i<=tmp; i++) {
        for(int j=i; j>0; j/=26) {
            putchar((char)(j%26+'a'));
        } putchar(' ');
    }
    return 0;
}

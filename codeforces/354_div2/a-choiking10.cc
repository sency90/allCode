#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int n;
    int minpos, maxpos, tmp;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&tmp);
        if(tmp==1) minpos = i;
        if(tmp==n) maxpos = i;
    }
    printf("%d", max({maxpos,minpos,n-1-maxpos,n-1-minpos}));
    return 0;
}

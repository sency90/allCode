#include <stdio.h>
#include <algorithm>
using namespace std;
int maxd[2][3], mind[2][3], v;
int main() {
    int n, t=1, i, j;
    scanf("%d", &n);
    for(i=0; i<3; i++) {
        scanf("%d", &maxd[0][i]);
        mind[0][i] = maxd[0][i];
    }
    for(i=1; i<n; i++) {
        t = 1-(i%2);
        for(j=0; j<3; j++) {
            scanf("%d", &v);
            if(j==0) {
                maxd[i%2][0] = max(maxd[t][0], maxd[t][1]) + v;
                mind[i%2][0] = min(mind[t][0], mind[t][1]) + v;
            } else if(j==1) {
                maxd[i%2][1] = max(maxd[t][0], max(maxd[t][1], maxd[t][2])) + v;
                mind[i%2][1] = min(mind[t][0], min(mind[t][1], mind[t][2])) + v;
            } else {
                maxd[i%2][2] = max(maxd[t][1], maxd[t][2]) + v;
                mind[i%2][2] = min(mind[t][1], mind[t][2]) + v;
            }
        }
    }
    sort(maxd[1-t], maxd[1-t]+3);
    sort(mind[1-t], mind[1-t]+3);
    printf("%d %d", maxd[1-t][2], mind[1-t][0]);
    return 0;
}

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    int t, n, sum, cnt, d;
    scanf("%d", &t);
    while(t--) {
        sum=0; cnt=0;
        v.clear();
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &d);
            v.push_back(d);
            sum += d;
        }
        for(int i=0; i<n; i++) {
            if(v[i]*n > sum) cnt++;
        }
        printf("%.3lf%%\n", (double)cnt/n*100);
    }
    return 0;
}

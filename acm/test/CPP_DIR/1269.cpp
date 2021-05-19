#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v, w;
vector<int>::iterator it;
int main() {
    int n, m, d, cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        v.push_back(d);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<m; i++) {
        scanf("%d", &d);
        it = lower_bound(v.begin(), v.end(), d);
        if(*it == d) cnt++;
    }
    printf("%d", n+m-cnt*2);
    return 0;
}

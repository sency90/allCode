#include <stdio.h>
#include <vector>
#include <algorithm>
std::vector<long long> v;
int main() {
    long long d;
    int cnt=1, maxCnt=1, maxIdx=0, n;

    scanf("%d", &n);
    int i=0; for(; i<n; i++) {
        scanf("%lld", &d);
        v.push_back(d);
    }
    std::stable_sort(v.begin(), v.end());
    for(i=1; i<n; i++) {
        if(v[i] == v[i-1]) cnt++;
        else if(maxCnt < cnt) {
            maxCnt = cnt;
            maxIdx = i-1;
            cnt = 1;
        } else cnt = 1;
    }
    if(maxCnt < cnt) {
        maxCnt = cnt;
        maxIdx = i-1;
    }
    printf("%lld\n", v[maxIdx]);
    return 0;
}

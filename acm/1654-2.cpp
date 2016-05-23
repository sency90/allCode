//왜 if(sum>=n)일때만 m값을 답으로 고려하는가?
//우리는 m이 답이되는 순간을 이분탐색을 통해서 포착해야 한다.
//즉, m이라는 값이 n과 같을 때, 이 중에서 가장 큰 값이 답이 되는 것이다.
//그러면 전체 m이 될수 있는 범위를 먼저 알아본다.
//랜선의 길이는 최소 1cm이고 최대 max(a[i])이다.
//그럼 해당 구간 안에서 n|n-1로 랜선의 개수가 딱 나뉘는 지점을 찾는데,
//if(sum>=n)일때는 답의 후보가 될 수 있고, if(sum<n)일 때는 답의 후보가 아예 될 수 없으므로,
//답의 후보가 되는 구간에서 계속 업뎃을 통해 답에 근접해 나가도록 한다.
#include <stdio.h>
long long a[10001];
long long k, n, mx=0, ans=0;
void bs(long long l, long long r) {
    if(l>r) return;
    long long m = (l+r)/2;
    long long sum=0;
    for(int i=0; i<k; i++) {
        sum += a[i]/m;
    }
    if(sum>=n) {
        bs(m+1,r);
        if(ans < m) ans = m;
    } else bs(l,m-1);
}
int main() {
    scanf("%lld%lld",&k,&n);
    for(int i=0; i<k; i++) {
        scanf("%lld", &a[i]);
        if(mx<a[i]) mx = a[i];
    }
    bs(1,mx);
    printf("%lld", ans);
    return 0;
}

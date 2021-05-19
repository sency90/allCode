#include <stdio.h>
#include <algorithm>
using namespace std;
int v[200000], n, c, ans=0;
void bs(int l, int r) {
    if(l>r) return;
    int m = (l+r)/2;
    int last=v[0], cnt=1;
    for(int i=1; i<n; i++) {
        if(v[i]-last>=m) {
            if(++cnt >= c) break;
            last=v[i];
        }
    }

    //아래의 if(cnt>=c)라는 것은
    //공유기 설치 개수가 많다는 것이므로, 기준으로 정한 m값(집들 사이의 간격)이 너무 작다는 것이다.
    //그래서 m을 늘려주려면 l값을 크게 해야하므로 bs(m+1,r)을 호출하면 된다.
    //그리고 cnt==c일때 m값이 답의 후보가 되므로 이때의 m을 ans에 update하는데
    //최대 거리이므로 가장 큰 값만 남기면 된다.
    if(cnt>=c) {
        if(ans<m) ans=m;
        bs(m+1,r);
    } else bs(l,m-1);
}
int main() {
    scanf("%d%d", &n, &c);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v,v+n);
    bs(1,v[n-1]-v[0]);
    printf("%d", ans);
    return 0;
}

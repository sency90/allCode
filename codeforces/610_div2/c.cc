//t_i-1에서 mandatory가 다 처리됐을 때에만
//더 문제를 풀 수 있는 시간이 있다면,
//easy부터 있는대로 다 처리하고 나서 hard를 처리하는 것이 최선의 선택이다.
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n,T,a,b;
vector<pll> p;
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        scanf("%lld%lld%lld%lld\n",&n,&T,&a,&b);
        p.clear(); p.resize(n);

        ll th=0, te=0;
        for(int i=0; i<n ;i++) {
            scanf("%lld", &p[i].second);
            if(p[i].second) th++;
            else te++;
        }
        for(int i=0; i<n; i++) scanf("%lld", &p[i].first);
        p.emplace_back(T+1,0);

        sort(p.begin(), p.end());

        ll h=0, e=0, ans=0;
        for(int i=0; i<=n; i++) {
            ll need = e*a + h*b;
            ll has = p[i].first-1 - need;

            if(has >= 0) {
                ll canE = min(te-e, has/a);
                has -= canE * a;

                ll canH = min(th-h, has/b);
                ans = max(ans, e+h+canE+canH);
            }

            int l = i;
            while(l<p.size() && p[i].first == p[l].first) {
                if(p[l].second) h++;
                else e++;
                l++;
            }
            i=l-1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

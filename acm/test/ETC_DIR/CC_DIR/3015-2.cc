#include <cstdio>
#include <stack>
using namespace std;
typedef long long ll;
stack<pair<ll,ll> > s;
pair<ll, ll> tmp;
int main() {
    int n;
    ll d, ans=0LL;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &d);
        tmp = make_pair(d,1LL);
        //first: 키, second: 동일한 키를 가진 닝겐들 수 (붙어있는 경우만 해당)
        //키가 같은 애들만 없어도 pair를 쓸 필요가 없다.
        while(!s.empty()) {
            if(s.top().first < d) {
                ans+=s.top().second;
                s.pop();
            } else if(s.top().first == d) {
                //왜 키가 같은 애들은 따로 처리해줘야 하는가?
                //잘 생각해보면 같은 키를 가진 애들의 수를 고려 안하고 pop하면,
                //나중에 같은 키 애들보다 큰 키가 입력으로 들어온 경우 해결할 수가 없음.
                ans+=s.top().second;
                tmp.second += s.top().second;
                s.pop();
            } else {
                ans++;
                break;
            }
        }
        s.push(tmp);
    }
    printf("%lld", ans);
    return 0;
}

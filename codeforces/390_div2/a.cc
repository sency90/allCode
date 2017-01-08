#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v;
int main() {
    int n; scanf("%d", &n);
    int s=1, sum=0, x;
    for(int i=1; i<=n; i++) {
        scanf("%d", &x);
        if(sum+x!=0) sum+=x;
        else {
            if(sum==0) continue;
            sum=x;
            v.push_back({s,i-1});
            s=i;
        }
    }
    if(sum==0) return 0&puts("NO");
    v.push_back({s,n});
    puts("YES");
    printf("%lu\n", v.size());
    for(auto &p: v) {
        printf("%d %d\n", p.first, p.second);
    }
    return 0;
}

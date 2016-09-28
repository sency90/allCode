#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
vector<pii> left, right;
int main() {
    int n,l,k,p,q;
    int tc; scanf("%d", &tc);
    while(tc--) {
        left.clear(); right.clear(); v.clear();
        scanf("%d%d%d",&n,&l,&k);
        for(int i=1; i<=n; i++) {
            scanf("%d%d",&p,&a);
            if(a<0) left.push_back(make_pair(p,-i));
            else right.push_back(make_pair(l-p,i));
        }

    }
    return 0;
}

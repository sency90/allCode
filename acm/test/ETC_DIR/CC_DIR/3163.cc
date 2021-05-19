#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<pii> v;
vector<int> order, left, right;

int main() {
    int n,l,k,p,a;
    int tc; scanf("%d", &tc);
    while(tc--) {
        left.clear(); right.clear(); v.clear(); order.clear();
        scanf("%d%d%d",&n,&l,&k);
        for(int i=0; i<n; i++) {
            scanf("%d%d",&p,&a);
            order.push_back(a);
            if(a<0) left.push_back(p);
            else right.push_back(l-p);
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        int i=0, j=0;
        while(i<left.size()&&j<right.size()) {
            if(left[i]<right[j]) {
                v.push_back(make_pair(left[i],order[i]));
                i++;
            } else {
                v.push_back(make_pair(right[j],order[n-j-1]));
                j++;
            }
        }
        while(i<left.size()) {
            v.push_back(make_pair(left[i],order[i]));
            i++;
        }
        while(j<right.size()) {
            v.push_back(make_pair(right[j],order[n-j-1]));
            j++;
        }
        sort(v.begin(), v.end());
        printf("%d\n", v[k-1].second);
    }
    return 0;
}

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a,v;
int main() {
    int t; scanf("%d", &t);
    for(int i=0; i<t; i++) {
        int n,s,k;
        scanf("%d%d%d",&n,&s,&k);
        a.clear(); a.resize(k);
        for(int j=0; j<k; j++) {
            scanf("%d", &a[j]);
        }

        v.clear();
        sort(a.begin(), a.end());
        for(int j=max(s-1002,1); j<=min(s+1002,n); j++) {
            auto it = lower_bound(a.begin(), a.end(), j);
            if(it!=a.end()) {
                if(*it != j) v.push_back(j);
            }
            else v.push_back(j);
        }

        auto it = lower_bound(v.begin(), v.end(), s);
        int h=n,l=n;
        if(it != v.end()) {
            if(*it == s) {
                puts("0");
                continue;
            }
            h = (*it)-s;
        }
        if(it != v.begin()) l = s-*(it-1);
        printf("%d\n", min(h,l));
    }
    return 0;
}

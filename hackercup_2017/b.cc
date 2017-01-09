#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v, need;
int main() {
    //freopen("./b_input.txt", "r", stdin);
    //freopen("./b_output.txt", "w", stdout);
    int tc; scanf("%d",&tc);
    for(int i=1; i<=50; i++) {
        if(need.begin() == need.end()) need.emplace_back(50);
        else if(need.back() != int((50+i-1)/i)) need.emplace_back((50+i-1)/i);
    }
    for(int z=1; z<=tc; z++) {
        int n; scanf("%d", &n);
        v.clear(); v.resize(n);
        for(int i=0; i<n; i++) scanf("%d", &v[i]);
        sort(v.begin(), v.end());

        int ans=0;
        for(int i=0; i<need.size()&&!v.empty(); i++) {
            auto it = lower_bound(v.begin(), v.end(), need[i]);
            int exist = v.end()-it;
            int pp=(need[need.size()-1-i]-1);
            if(it!=v.end()) v.erase(it, v.end());
            if(pp==0) ans+=exist;
            else {
                int rm = min(int(v.size()/pp),exist);
                v.erase(v.begin(), v.begin()+rm*pp);
                ans += rm + (exist-rm)/(pp+1);
            }
        }
        printf("Case #%d: %d\n",z,ans);
    }
    return 0;
}

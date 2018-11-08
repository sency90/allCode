#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
map<int, int> ans;
bool noPrime[160001];
vector<int> v;
int main() {
    noPrime[0] = noPrime[1] = true;
    for(int i=2; i<400; i++) {
        for(int j=i*i; j<=160000; j+=i) {
            noPrime[j] = true;
        }
    }
    for(int i=0; i<=160000; i++) {
        if(!noPrime[i]) v.push_back(i);
    }
    int n,x;  scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        ans.clear();
        for(int j=0; j<v.size(); j++) {
            while(x%v[j] == 0) {
                ans[v[j]]++;
                x/=v[j];
            }
        }
        for(auto &it : ans) {
            printf("%d %d\n", it.first, it.second);
        }
    }
    return 0;
}
